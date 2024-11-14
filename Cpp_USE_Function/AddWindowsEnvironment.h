#pragma once

#include <iostream>
#include <windows.h>
#include <string>

// 以注册表方式读取PATH路径
std::wstring getUserPathFromRegistry() {
    HKEY hKey;
    wchar_t buffer[32767];  // 用于存储读取的路径
    DWORD bufferSize = sizeof(buffer);

    // 打开 HKEY_CURRENT_USER\Environment 注册表键
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Environment", 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open registry key for user environment variables." << std::endl;
        return L"";
    }

    // 从注册表中获取 PATH 变量的值
    if (RegQueryValueExW(hKey, L"PATH", nullptr, nullptr, reinterpret_cast<BYTE*>(buffer), &bufferSize) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to read PATH from registry." << std::endl;
        RegCloseKey(hKey);
        return L"";
    }

    RegCloseKey(hKey);
    return std::wstring(buffer);
}

// 修改用户级别环境变量
bool setUserEnvironmentVariable(const std::wstring& name, const std::wstring& value) {
    HKEY hKey;
    // 打开注册表键：用户环境变量位于 HKEY_CURRENT_USER\Environment
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Environment", 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open registry key for user environment variables." << std::endl;
        return false;
    }

    // 设置环境变量的值
    if (RegSetValueExW(hKey, name.c_str(), 0, REG_EXPAND_SZ, reinterpret_cast<const BYTE*>(value.c_str()), (value.size() + 1) * sizeof(wchar_t)) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to set registry value for: " << name << std::endl;
        RegCloseKey(hKey);
        return false;
    }

    RegCloseKey(hKey);
    // 通知系统更新环境变量
    SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0, reinterpret_cast<LPARAM>(L"Environment"), SMTO_ABORTIFHUNG, 5000, nullptr);
    return true;
}

// 修改系统级别环境变量
bool setPermanentEnvironmentVariable(const std::wstring& name, const std::wstring& value) {
    HKEY hKey;
    // 打开注册表键：SYSTEM 环境变量位于 HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open registry key for environment variables." << std::endl;
        return false;
    }
    // 设置环境变量的值
    if (RegSetValueExW(hKey, name.c_str(), 0, REG_EXPAND_SZ, reinterpret_cast<const BYTE*>(value.c_str()), (value.size() + 1) * sizeof(wchar_t)) != ERROR_SUCCESS) {
        std::wcerr << L"Failed to set registry value for: " << name << std::endl;
        RegCloseKey(hKey);
        return false;
    }

    RegCloseKey(hKey);
    // 通知系统更新环境变量
    SendMessageTimeoutW(HWND_BROADCAST, WM_SETTINGCHANGE, 0, reinterpret_cast<LPARAM>(L"Environment"), SMTO_ABORTIFHUNG, 5000, nullptr);
    return true;
}

// 添加路径至 PATH
bool addUserPathEnvironment(const std::wstring& add_path) {
    // 获取用户级别的 PATH 环境变量
    std::wstring currentPath = getUserPathFromRegistry();
    if (!currentPath.empty()) {
        //std::wcout << L"User PATH: " << currentPath << std::endl;
        std::wcout << L"--Tip: User PATH Load SUCCESS! :) " << std::endl;
    } else {
        std::wcerr << L"--Tip: Failed to retrieve user PATH. XX " << std::endl;
    }
    std::wstring env_path = add_path + L"\\bin";
    std::wstring newPath = env_path + L";" + currentPath;

    // 更新 PATH 环境变量
    if (setUserEnvironmentVariable(L"PATH", newPath)) {
        std::wcout << L"--Tip: Add [" << add_path << "] to PATH SUCCESS! :) " << std::endl;

    } else {
        std::wcerr << L"--Tip: Failed to add [" << add_path << "] to PATH. XX " << std::endl;
        return false;
    }
    return true;
}