/*
 *  A string has unique chars?
 *  Using and not using data structures
 *  Solution on C++
 *
 *  Usage:
 *  1) Build a string
 *  2) uniqueCharsHash(stringToTest); 
 *  2) uniqueCharsNoHash(stringToTest); 
 *  
 *  Created by Guillermo Hernandez on 9/20/13
 *  https://github.com/0w3w
 *  http://www.linkedin.com/in/guillermohernandezmolina
 *
 */

#include <iostream>
#include <unordered_map>

int uniqueCharHash(const char* str){
	int count;
	std::unordered_map<char, int> htable;
	while(*str != '\0'){
		htable[*str]++;
		count = htable[*str];
		if(count > 1){
			return 0;
		}
		str++;
	}
	return 1;
}

int uniqueCharsNoHash(const char* str){
	const char *str2 = str;
	while(*str != '\0'){
		str2 = str + 1;
		while(*str2 != '\0'){
			if(*str == *str2){
				return 0;
			}
			str2++;
		}
		str++;
	}
	return 1;
}

int main(){
	const char* testStringTrue = "abcde";
	const char* testStringFalse = "abcdee";
	std::cout << "abcde with hashtable is : " << uniqueCharHash(testStringTrue) << std::endl;
	std::cout << "abcde without hashtable is : " << uniqueCharsNoHash(testStringTrue) << std::endl;
	std::cout << "abcdee with hashtable is : " << uniqueCharHash(testStringFalse) << std::endl;
	std::cout << "abcdee without hashtable is : " << uniqueCharsNoHash(testStringFalse) << std::endl;
	return 0;
}
