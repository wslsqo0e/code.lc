/*************************************************************************
> File Name:  different_ways_to_add_parentheses.cpp
> Author: shenming
> Created Time: Mon Jan 27 12:17:29 2020
************************************************************************/

class Solution_ref {
public:
    int calc(int n1,int n2,char c){
        if(c=='+')
            return n1+n2;
        if(c=='-')
            return n1-n2;
        else
            return n1*n2;
    }

    void helper(vector<int>& res, string s, int low, int high) {
        int indexplus = s.find('+');
        int indexminus= s.find('-');
        int indexprod = s.find('*');
        if(indexprod==string::npos and indexminus==string::npos and indexplus==string::npos){
            res.push_back(stoi(s));
            return;
        }
        int curr = indexplus;
        while(curr!=string::npos) {
            vector<int> left;
            vector<int> right;
            helper(left, s.substr(0, curr), low, curr-1);
            helper(right, s.substr(curr+1, high), curr+1, high);
            for (auto leftout:left) {
                for (auto rightout:right) {
                    res.push_back(calc(leftout, right, '+'));
                }
            }
            curr=s.find('+',curr+1);
        }

        curr=indexminus;
        while(curr!=string::npos){
            vector<int> left;
            vector<int> right;
            helper(left,s.substr(0,curr),low,curr-1);
            helper(right,s.substr(curr+1),curr+1,high);
            for(auto leftout:left){
                for(auto rightout:right){
                    res.push_back(calc(leftout,rightout,'-'));
                }
            }
            curr=s.find('-',curr+1);
        }
        curr=indexprod;
        while(curr!=string::npos){
            vector<int> left;
            vector<int> right;
            helper(left,s.substr(0,curr),low,curr-1);
            helper(right,s.substr(curr+1),curr+1,high);
            for(auto leftout:left){
                for(auto rightout:right){
                    res.push_back(calc(leftout,rightout,'*'));
                }
            }
            curr=s.find('*',curr+1);
        }
    }

    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int n=input.size();
        helper(res,input,0,n-1);
        return res;
    }
}

class Solution {
public:
    struct ele {
        char oper;
        int val;
        ele* next;
        ele* pre;
        ele(char op, int val) : oper(op), val(val), next(NULL), pre(NULL) {}
    };
    vector<int> diffWaysToCompute(string input) {
        return NULL;
    }
};

int main()
{
    Solution s;

    return 0;
}
