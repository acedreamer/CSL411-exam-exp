#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void detect(char buffer[]);
bool is_operator(char buffer[]);
bool is_special(char buffer[]);
bool is_keyword(char buffer[]);
bool is_constant(char buffer[]);
bool is_identifier(char buffer[]);

int main() {
    FILE *ptr;
    char ch;
    char buffer[50];
    int idx = 0;
    
    ptr = fopen("input.txt", "r");
    if (ptr == NULL) {
        printf("Error: Could not open 'input.txt'. Please ensure the file exists in the current directory.\n");
        return 1;
    }
    
    printf("=========================================\n");
    printf("        C-BASED LEXICAL ANALYZER         \n");
    printf("=========================================\n");
    printf("%-15s\t%-15s\n", "LEXEME", "TOKEN TYPE");
    printf("-----------------------------------------\n");
    
    while ((ch = fgetc(ptr)) != EOF) {
        // Delimiters: spaces, horizontal tabs, newlines
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (idx > 0) {
                buffer[idx] = '\0';
                detect(buffer);
                idx = 0;
            }
        }
        // Self-delimiting operators and punctuation symbols
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
                 ch == ';' || ch == ',' || ch == '(' || ch == ')' || 
                 ch == '{' || ch == '}' || ch == '[' || ch == ']') {
            
            // If characters preceded this delimiter without whitespace (e.g., "b+c")
            if (idx > 0) {
                buffer[idx] = '\0';
                detect(buffer);
                idx = 0;
            }
            // Classify the operator / special symbol character itself
            char temp[2] = {ch, '\0'};
            detect(temp);
        }
        // Normal characters forming identifier, keyword, or constant
        else {
            buffer[idx++] = ch;
        }
    }
    
    // Flush any token remaining when EOF is encountered
    if (idx > 0) {
        buffer[idx] = '\0';
        detect(buffer);
    }
    
    fclose(ptr);
    return 0;
}

void detect(char buffer[]) {
    if (strlen(buffer) == 0) return;
    
    // Priority 1: Keywords must be checked before Identifiers!
    if (is_keyword(buffer)) {
        printf("%-15s\t: Keyword\n", buffer);
    } 
    // Priority 2: Operators
    else if (is_operator(buffer)) {
        printf("%-15s\t: Operator\n", buffer);
    } 
    // Priority 3: Special Symbols
    else if (is_special(buffer)) {
        printf("%-15s\t: Special Symbol\n", buffer);
    } 
    // Priority 4: Constants
    else if (is_constant(buffer)) {
        printf("%-15s\t: Constant\n", buffer);
    } 
    // Priority 5: Identifiers
    else if (is_identifier(buffer)) {
        printf("%-15s\t: Identifier\n", buffer);
    } 
    // Fallback: Lexical Error / Invalid Token
    else {
        printf("%-15s\t: Invalid Token\n", buffer);
    }
}

bool is_operator(char buffer[]) {
    char *operators[] = {"+", "-", "*", "/", "%", "=", "==", "<", ">", "<=", ">=", "!="};
    int count = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < count; i++) {
        if (strcmp(buffer, operators[i]) == 0) return true;
    }
    return false;
}

bool is_special(char buffer[]) {
    char *specials[] = {";", ",", "(", ")", "{", "}", "[", "]"};
    int count = sizeof(specials) / sizeof(specials[0]);
    for (int i = 0; i < count; i++) {
        if (strcmp(buffer, specials[i]) == 0) return true;
    }
    return false;
}

bool is_keyword(char buffer[]) {
    char *keywords[] = {
        "int", "float", "char", "double", "bool", "void",
        "if", "else", "for", "while", "do", "break", 
        "continue", "return", "switch", "case", "default"
    };
    int count = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < count; i++) {
        if (strcmp(buffer, keywords[i]) == 0) return true;
    }
    return false;
}

bool is_constant(char buffer[]) {
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (!isdigit(buffer[i])) return false;
    }
    return true;
}

bool is_identifier(char buffer[]) {
    if (!isalpha(buffer[0]) && buffer[0] != '_') return false;
    for (int i = 1; buffer[i] != '\0'; i++) {
        if (!isalnum(buffer[i]) && buffer[i] != '_') return false;
    }
    return true;
}
