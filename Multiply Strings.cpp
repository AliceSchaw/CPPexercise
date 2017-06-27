<<<<<<< HEAD
<<<<<<< HEAD
class Solution {
public:
    string multiply(string num1, string num2) {
                
        int l1=num1.size(),l2=num2.size();
        if (l1==0||l2==0||num1=="0"||num2=="0") return "0";
        
        vector<int> v(l1+l2,0);
 
        for (int i=0;i<l1;i++){
            int carry=0;
            int n1=(int)(num1[l1-i-1]-'0');//Calculate from rightmost to left
            for (int j=0;j<l2;j++){
                int n2=(num2[l2-j-1]-'0');//Calculate from rightmost to left
                
                int sum=n1*n2+v[i+j]+carry;
                carry=sum/10;
                v[i+j]=sum%10;
            }
            if (carry>0)
                v[i+l2]+=carry;

        }
        int start=l1+l2-1;
        while(v[start]==0) start--;
        
        string s="";
        for (int i=start;i>=0;i--)
            s+=(char)(v[i]+'0');
        return s;
    }
};

//without reverse
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }
        
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
=======
class Solution {
public:
    string multiply(string num1, string num2) {
                
        int l1=num1.size(),l2=num2.size();
        if (l1==0||l2==0||num1=="0"||num2=="0") return "0";
        
        vector<int> v(l1+l2,0);
 
        for (int i=0;i<l1;i++){
            int carry=0;
            int n1=(int)(num1[l1-i-1]-'0');//Calculate from rightmost to left
            for (int j=0;j<l2;j++){
                int n2=(num2[l2-j-1]-'0');//Calculate from rightmost to left
                
                int sum=n1*n2+v[i+j]+carry;
                carry=sum/10;
                v[i+j]=sum%10;
            }
            if (carry>0)
                v[i+l2]+=carry;

        }
        int start=l1+l2-1;
        while(v[start]==0) start--;
        
        string s="";
        for (int i=start;i>=0;i--)
            s+=(char)(v[i]+'0');
        return s;
    }
};

//without reverse
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }
        
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
>>>>>>> 76dd5de5e755fac11ea9f1568e19618b0f421cc7
=======
class Solution {
public:
    string multiply(string num1, string num2) {
                
        int l1=num1.size(),l2=num2.size();
        if (l1==0||l2==0||num1=="0"||num2=="0") return "0";
        
        vector<int> v(l1+l2,0);
 
        for (int i=0;i<l1;i++){
            int carry=0;
            int n1=(int)(num1[l1-i-1]-'0');//Calculate from rightmost to left
            for (int j=0;j<l2;j++){
                int n2=(num2[l2-j-1]-'0');//Calculate from rightmost to left
                
                int sum=n1*n2+v[i+j]+carry;
                carry=sum/10;
                v[i+j]=sum%10;
            }
            if (carry>0)
                v[i+l2]+=carry;

        }
        int start=l1+l2-1;
        while(v[start]==0) start--;
        
        string s="";
        for (int i=start;i>=0;i--)
            s+=(char)(v[i]+'0');
        return s;
    }
};

//without reverse
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }
        
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
>>>>>>> 76dd5de5e755fac11ea9f1568e19618b0f421cc7
};