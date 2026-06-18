class Solution {
public:


    string encode(vector<string>& strs) {

    string coded = "";

    for(string s : strs){

        int len = s.length();

        coded += (char)0xFF;
        coded += (char)(len >> 8);
        coded += (char)(len & 0xFF);
        coded += s;
    }

    return coded;
    }

    vector<string> decode(string s) {

    vector<string> result;

    for(int i = 0; i < s.length(); i++){

        if(s[i] == (char)0xFF){

            int currentLength =
                ((unsigned char)s[i+1] << 8) |
                (unsigned char)s[i+2];

            result.push_back(s.substr(i+3, currentLength));

            i += currentLength + 2;
        }
    }

    return result;
    }

    // string encode(vector<string>& strs) {

    //     string coded = "";

    //     for(string s:strs){

    //         coded = coded + (char)0xFF + (char)s.length() + s;
    //         //cout << coded << endl;

    //         //cout << s.length() << endl;
    //     }

    //     return coded;
    // }

    // vector<string> decode(string s) {

    //     vector<string> result;
    //     for(int i = 0; i < s.length(); i++){
    //         int currentLength = 0;

    //         if(s[i] == (char)0xFF){
    //             currentLength = (int)s[i+1];
    //             result.push_back(s.substr(i+2, currentLength));

    //             i = i + 1 + currentLength;
    //         }



    //     }


    //     return result;
    // }
    
};
