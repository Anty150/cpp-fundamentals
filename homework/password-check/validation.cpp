#include "validation.hpp"
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string getErrorMessage(const ErrorCode& errCode){
    switch(errCode){
        case ErrorCode::Ok:
            return "Ok";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Password needs to have at least nine characters";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Password needs to have at least one number";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Password needs to have at least one special character";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Password needs to have at least one uppercase letter";
            break;
        case ErrorCode::PasswordsDoNotMatch:
            return "Passwords do not match";
            break;
    }
}
bool doPasswordsMatch(const string& pass1, const string& pass2){
    if(pass1 == pass2)
        return true;
    return false;
}
ErrorCode checkPasswordRules(const string& pass){
    if(pass.length() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    if(!any_of(pass.begin(), pass.end(), ::isdigit))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    bool specialCheck = false;
    for(int i=0;i<pass.length();i++)
    {
        if ((pass[i]>=48 && pass[i]<=57)||(pass[i]>=65 && pass[i]<=90)||(pass[i]>=97 && pass[i]<=122))
            continue;
        else{
            specialCheck = true;
            break;
        }
    }
    if(!specialCheck)
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    bool upperCheck = false;
    for(int i=0;i<pass.length();i++){
        if(isupper(pass[i])){
            bool upperCheck = true;
            break;
        }
    }
    if(!upperCheck)
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    return ErrorCode::Ok;
}
ErrorCode checkPassword(const string& pass1, const string& pass2){
    if(!doPasswordsMatch(pass1, pass2))
        return ErrorCode::PasswordsDoNotMatch;
    return checkPasswordRules(pass1);
}