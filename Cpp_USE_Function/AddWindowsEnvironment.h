#pragma once

#include <iostream>
#include <windows.h>
#include <string>

// ��ע���ʽ��ȡPATH·��
std::wstring getUserPathFromRegistry() {
    HKEY hKey;
    wchar_t buffer[32767];  // ���ڴ洢��ȡ��·��
    DWORD bufferSize = sizeof(buffer);

    // �� HKEY_CURRENT_USER\Environment ע����
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Environment", 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open registry key for user environment variables." << std::endl;
        return L"";
    }

    // ��ע����л�ȡ PATH ������ֵ
    if (RegQueryValueExW(hKey, L"PATH", nullptr, nullptr, reinterpret_cast<BYTE*>(buffer), &bufferSize) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to read PATH from registry." << std::endl;
        RegCloseKey(hKey);
        return L"";
    }

    RegCloseKey(hKey);
    return std::wstring(buffer);
}

// �޸��û����𻷾�����
bool setUserEnvironmentVariable(const std::wstring& name, const std::wstring& value) {
    HKEY hKey;
    // ��ע�������û���������λ�� HKEY_CURRENT_USER\Environment
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Environment", 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open registry key for user environment variables." << std::endl;
        return false;
    }

    // ���û���������ֵ
    if (RegSetValueExW(hKey, name.c_str(), 0, REG_EXPAND_SZ, reinterpret_cast<const BYTE*>(value.c_str()), (value.size() + 1) * sizeof(wchar_t)) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to set registry value for: " << name << std::endl;
        RegCloseKey(hKey);
        return false;
    }

    RegCloseKey(hKey);
    // ֪ͨϵͳ���»�������
    SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0, reinterpret_cast<LPARAM>(L"Environment"), SMTO_ABORTIFHUNG, 5000, nullptr);
    return true;
}

// �޸�ϵͳ���𻷾�����
bool setPermanentEnvironmentVariable(const std::wstring& name, const std::wstring& value) {
    HKEY hKey;
    // ��ע������SYSTEM ��������λ�� HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open registry key for environment variables." << std::endl;
        return false;
    }
    // ���û���������ֵ
    if (RegSetValueExW(hKey, name.c_str(), 0, REG_EXPAND_SZ, reinterpret_cast<const BYTE*>(value.c_str()), (value.size() + 1) * sizeof(wchar_t)) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to set registry value for: " << name << std::endl;
        RegCloseKey(hKey);
        return false;
    }

    RegCloseKey(hKey);
    // ֪ͨϵͳ���»�������
    SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0, reinterpret_cast<LPARAM>(L"Environment"), SMTO_ABORTIFHUNG, 5000, nullptr);
    return true;
}

// ���·���� PATH
bool addUserPathEnvironment(const std::wstring& add_path) {
    // ��ȡ�û������ PATH ��������
    std::wstring currentPath = getUserPathFromRegistry();
    if (!currentPath.empty()) {
        //std::wcout << L"User PATH: " << currentPath << std::endl;
        std::wcout << L"--Tip: User PATH Load SUCCESS! :) " << std::endl;
    } else {
        std::wcerr << L"--Tip: Failed to retrieve user PATH. XX " << std::endl;
    }
    std::wstring env_path = add_path + L"\\bin";
    std::wstring newPath = env_path + L";" + currentPath;

    // ���� PATH ��������
    if (setUserEnvironmentVariable(L"PATH", newPath)) {
        std::wcout << L"--Tip: Add [" << add_path << "] to PATH SUCCESS! :) " << std::endl;

    } else {
        std::wcerr << L"--Tip: Failed to add [" << add_path << "] to PATH. XX " << std::endl;
        return false;
    }
    return true;
}