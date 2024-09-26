package com.example.loginpage.tools;

public class StringChecker {
    public static int checkString(String str) {
        if (str == null || str.isEmpty()) {
            return 0;
        }
        // 正则表达式匹配特殊字符
        if (str.matches(".*[^a-zA-Z0-9 ].*")) {
            return -1;
        }
        return 1; // 如果字符串不为空且没有特殊字符
    }
}