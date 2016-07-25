//https://leetcode.com/problems/multiply-strings/
// I'm stupid to write a super inelegant answer to this question, after that I searched and 
// found a decent solution. Now leave me alone I just wanna cry for my stupidity.

// Stupid one(mine):
class Solution {
public:
    string multiply(string num1, string num2) {
        string res="";
        if(num1=="0" || num2=="0") return "0";
        for(int i=num2.length()-1; i>=0; --i){
            string temp = helper(num1, num2[i]);
            int n=num2.length()-1-i;
            string str(n,'0');
            temp.insert(temp.length(),str);
            res=addstr(res,temp);
        }
        return res;
    }
    string helper(string num1, char num2){
        int carry=0;
        for(int i=num1.length()-1; i>=0; --i){
            int temp= (num1[i]-'0')*(num2-'0')+carry;
            num1[i]=temp%10+'0';
            carry=temp/10;
        }
        if(carry) num1.insert(num1.begin(),carry+'0');
        return num1;
    }
    string addstr(string num1, string num2){
        int n=abs(int(num1.length())-int(num2.length()));
        string str(n,'0');
        if(num1.length()<num2.length()) num1.insert(0,str);
        else num2.insert(0,str);
        int carry=0;
        n=int(num1.length());
        string res(n,'0');
        for(int i=n-1; i>=0; --i){
            int temp=(num1[i]-'0')+(num2[i]-'0')+carry;
            res[i]=temp%10+'0';
            carry=temp/10;
        }
        if(carry) res.insert(res.begin(),carry+'0');
        return res;
    }
};

// Clever one(http://bangbingsyb.blogspot.jp/2014/11/leetcode-multiply-strings.html):

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) return "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ret(num1.size()+num2.size(),'0');
        
        for(int j=0; j<num2.size(); j++) {
            int carry = 0;
            int val = num2[j] - '0';
            for(int i=0; i<num1.size(); i++) {
                carry += ((num1[i]-'0')*val + (ret[i+j]-'0'));
                ret[i+j] = carry%10 + '0';
                carry /= 10;
            }
            if(carry!=0) ret[num1.size()+j] = carry + '0';
        }
        reverse(ret.begin(),ret.end());
        
        int count = 0;
        while(count<ret.size()-1 && ret[count]=='0') count++;
        ret.erase(0,count);
        return ret;
    }
};