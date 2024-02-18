#include<iostream>
#include<string>
using namespace std;

int isnum(char s) {
    char num[] = { '0','1','2','3','4','5','6','7','8','9' };
    for (int i = 0; i < 10; i++) {
        if (s == num[i]) return 1;
    }
    return 0;
}


int main()
{
    string id; cin >> id;
	
    string ans;
    for (int i = 0; i < id.length(); i++) {
        if (id[i] >= 'A' && id[i] <= 'Z') {
            id[i] = char(tolower(id[i]));
        }
        ans += id[i];
    }
    
    //2단계
    id = ans; ans = "";

    for (int i = 0; i < id.length(); i++) {
        if (id[i] >= 'a' && id[i] <= 'z') ans += id[i];
        else if (id[i] == '-' || id[i] == '_' || id[i] == '.')
            ans += id[i];
        else if (isnum(id[i])) ans += id[i];
    }
 
    //3단계
    id = ans; ans = "";

    while (1) {
        ans = "";
        int check = 0;
        for (int i = 0; i < id.length() - 1; i++) {
            if (id[i] == '!') continue;
            if (id[i] == '.' && id[i + 1] == '.') {
                check = 1;
                id[i + 1] = '!';
            }
        }

        for (int i = 0; i < id.length(); i++) {
            if (id[i] != '!') ans += id[i];
        }
        id = ans;
        
        if (!check) break;
    }
    
    
    //4단계
    id = ans; ans = "";
    
    if(id[0] == '.') id[0] = '!';
    if (id != "" && id[id.length() - 1] == '.') id[id.length() - 1] = '!';
    for (int i = 0; i < id.length(); i++) {
        if (id[i] != '!') ans += id[i];
    }
    
    //5단계
    id = ans; ans = "";
    
    if (id == "") {
        ans += 'a';
        id = ans; ans = "";
    }
    
    //6단계
    
    if (id.length() > 15) {
        for (int i = 0; i < 15; i++) ans += id[i];
        id = ans; ans = "";
    }


    if (id[id.length() - 1] == '.') {
        ans = "";
        for (int i = 0; i < id.length() - 1; i++) ans += id[i];
        id = ans;
    }
   

    //7단계
    
    if (id.length() < 3) {
        while (id.length() < 3) {
            id += id[id.length() - 1];
        }
    }
    ans = id;
    cout << ans;

	return 0;
}