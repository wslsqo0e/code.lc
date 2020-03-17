/*************************************************************************
> File Name:  Valid_IP_address.cpp
> Author: shenming
> Created Time: Tue Jan 28 14:13:28 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    bool is_ipv4_par(string ss) {
        for (auto c : ss) {
            if (c < '0' || c > '9') {
                return false;
            }
        }
        if (ss.size() == 0) {
            return false;
        }
        if (ss.size() != 1) {
            if (ss[0] == '0') {
                return false;
            }
        }
        try {
            int i = stoi(ss);
            // printf("%s\n", ss.c_str());
            if (i<=255 && i>=0) {
                return true;
            } else {
                return false;
            }
        }
        catch (...) {
            return false;
        }
        return false;
    }
    bool is_ipv6_par(string ss) {
        for (auto c : ss) {
            if ((c < '0' || c > '9') && (c < 'a' || c >'z') && (c < 'A' || c >'Z')) {
                return false;
            }
        }
        if (ss.size() == 0) {
            return false;
        }
        // if (ss.size() > 1) {
        //     if (ss.find("00") == 0) {
        //         return false;
        //     }
        // }
        try {
            int i =stoi(ss, NULL, 16);
            // printf("%s %d\n", ss.c_str(), i);
            return true;
        } catch (...) {
            return false;
        }
        return false;
    }
    bool check_ipv4(string IP) {
        for (int i = 0; i < 3; i++) {
            size_t pos = IP.find(".");
            if (pos == string::npos) {
                return false;
            }
            if (!is_ipv4_par(IP.substr(0, pos))) {
                return false;
            }
            IP = IP.substr(pos+1);
        }
        if (!is_ipv4_par(IP)) {
            return false;
        }
        return true;
    }

    bool check_ipv6(string IP) {
        for (int i = 0; i < 7; i++) {
            size_t pos = IP.find(":");
            if (pos == string::npos) {
                return false;
            }
            if (!is_ipv6_par(IP.substr(0, pos))) {
                //printf("H %s\n", IP.substr(0, pos).c_str());
                return false;
            }
            IP =IP.substr(pos + 1);
        }
        if (!is_ipv6_par(IP)) {
            //printf("H\n");
            return false;
        }
        return true;
    }
    string validIPAddress(string IP) {
        if (check_ipv4(IP)) {
            return "IPv4";
        }
        if (check_ipv6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
};

int main()
{
    Solution s;
    // string ret = s.validIPAddress("092.158.1.1");
    // string ret = s.validIPAddress("2001:db8:85a3:0:0:8A2E:0370:7334");
    // string ret = s.validIPAddress("2001:db8:85a3:0:0:8A2E:0370:7334:");
    string ret = s.validIPAddress("12.12.12");
    printf("%s\n", ret.c_str());
    return 0;
}
