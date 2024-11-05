"""
简单的LangChain构建聊天机器人实例，实现了提示词设置，使用Graph实现消息持久化，使用trim_messages进行最大token限制，实现流式传输显示
"""
from langchain_ollama import OllamaLLM, OllamaEmbeddings
from langchain_openai import ChatOpenAI

model = OllamaLLM(model='llama3.2:latest')

from langchain_core.messages import BaseMessage, HumanMessage, AIMessage
from langchain_core.messages import SystemMessage, trim_messages

trimmer = trim_messages(
    max_tokens=65,
    strategy="last",
    token_counter=ChatOpenAI(model="gpt-3.5-turbo",api_key="sk-wTSoS0uR3eHrycjb0502Af768eAa4d429cDd0d178c7a995b", base_url="https://api.bianxie.ai/v1"),
    include_system=True,
    allow_partial=False,
    start_on="human",
)

messages = [
    SystemMessage(content="you're a good assistant"),
    HumanMessage(content="hi! I'm yyz"),
    AIMessage(content="hi!"),
    HumanMessage(content="I like vanilla ice cream"),
    AIMessage(content="nice"),
    HumanMessage(content="whats 2 + 2"),
    AIMessage(content="4"),
    HumanMessage(content="thanks"),
    AIMessage(content="no problem!"),
    HumanMessage(content="having fun?"),
    AIMessage(content="yes!"),
]

from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder
prompt = ChatPromptTemplate.from_messages(
    [
        (
            "system",
            "You are a helpful assistant. Answer all questions to the best of your ability in {language}.",
        ),
        MessagesPlaceholder(variable_name="messages"),
    ]
)

from typing import Sequence

from langgraph.constants import START
from langgraph.graph import StateGraph

from langgraph.graph.message import add_messages
from typing_extensions import Annotated, TypedDict
from langgraph.checkpoint.memory import MemorySaver


class State(TypedDict):
    messages: Annotated[Sequence[BaseMessage], add_messages]
    language: str

workflow = StateGraph(state_schema=State)

def call_model(state: State):
    chain = prompt | model
    trimmed_messages = trimmer.invoke(state["messages"])
    response = chain.invoke(
        {"messages": trimmed_messages, "language": state["language"]}
    )
    return {"messages": [response]}

workflow.add_edge(START, "model")
workflow.add_node("model", call_model)

memory = MemorySaver()
app = workflow.compile(checkpointer=memory)

# 现在，如果我们尝试询问模型我们的姓名，它将不知道，因为我们修剪了聊天历史记录的那一部分
config = {"configurable": {"thread_id": "foryyz2"}}
query = "What is my name?"
language = "English"

input_messages = messages + [HumanMessage(query)]
output = app.invoke(
    {"messages": input_messages, "language": language},
    config,
)
output["messages"][-1].pretty_print()

# 但是，如果我们询问最近几条消息中的信息，它会记住
config = {"configurable": {"thread_id": "abc678"}}
query = "What math problem did I ask?"
language = "English"

input_messages = messages + [HumanMessage(query)]
output = app.invoke(
    {"messages": input_messages, "language": language},
    config,
)
output["messages"][-1].pretty_print()

# 这里将模型换成第三方大模型，因为ollama没有token无法按流输出(maybe)
model = ChatOpenAI(model="gpt-3.5-turbo",api_key="sk-wTSoS0uR3eHrycjb0502Af768eAa4d429cDd0d178c7a995b", base_url="https://api.bianxie.ai/v1")
config = {"configurable": {"thread_id": "abc789"}}
query = "Hi I'm yyz, please tell me a joke."
language = "English"

input_messages = [HumanMessage(query)]
for chunk, metadata in app.stream(
    {"messages": input_messages, "language": language},
    config,
    stream_mode="messages",
):
    if isinstance(chunk, AIMessage):  # Filter to just model responses
        print(chunk.content, end="|")