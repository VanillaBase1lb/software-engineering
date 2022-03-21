#include <iostream>
#include <string>
using namespace std;

// PROXY BEGIN ClassWithProxy
class ClassWithProxy{
public:
    char read_characters[1000];
// PROXY FN BEGIN
    int characterCompare(char arr1[], char arr2[], int n){
        for (int i = 0; i < n; i++){
            if (arr1[i] != arr2[i]){
                return 0;
            }
        }
        return 1;
    }
// PROXY FN END
// PROXY FN BEGIN
    void nameChange(char name[], char full[], int k){
        for (int i = 0; i < 100; i++){
            name[i] = full[i + k];
        }
    }
// PROXY FN END
// PROXY FN BEGIN
    int considerSpaces(char arr[]){
        int i = 0;
        while (arr[i] != '\0'){
            if (arr[i] != ' '){
                return 0;
            }
            i++;
        }
        return 1;
    }
// PROXY FN END
// PROXY FN BEGIN
    int condiderEmptyLines(char arr[]){
        int i = 0;
        while (arr[i] != '\n'){
            if (arr[i] != ' '){
                return 0;
            }
            i++;
        }
        return 1;
    }
// PROXY FN END
// PROXY FN BEGIN
    void fileHandler(char pb[], char pe[], char fb[], char fe[], int prb, int pre, int fnb, int fne){
        char fileName[50];
        cin >> fileName;
        cout << "\n";

        FILE *fp1;
        fp1 = fopen(fileName, "r");
        if (fp1 == NULL){
            cout << "File could not be opened. Check file name again";
            return;
        }

        char proxy_name[100];
        int proxy_loc = 0;
        int func_count = 0;
        int total_loc = 0;

        while (fgets(read_characters, 1000, fp1) != NULL){
            if (condiderEmptyLines(read_characters) == 0){
                total_loc++;
            }
            if (characterCompare(read_characters, pb, prb - 1) == 1){
                nameChange(proxy_name, read_characters, prb - 1);
                cout << "Proxy Name: " << proxy_name;
                proxy_loc = 1;
                func_count = 0;
            }
            if (characterCompare(read_characters, fb, fnb - 1) == 1){
                func_count++;
            }
            if (characterCompare(read_characters, pe, pre - 1) != 1){
                if (condiderEmptyLines(read_characters) == 0){
                    proxy_loc++;
                }
                continue;
            }
            cout << "Number of Methods: " << func_count << "\n";
            cout << "Proxy LOC: " << proxy_loc << "\n\n";
        }
        if (considerSpaces(read_characters) == 1){
            total_loc--;
        }
        cout << "Total LOC: " << total_loc << "\n\n\n\n";
        fclose(fp1);
    }
// PROXY FN END
};
// PROXY END ClassWithProxy
// PROXY BEGIN StartingTask
class StartingTask{
public:
// PROXY FN BEGIN
    void printWelcomeMsg(){
        cout << "Enter the filename of the program(for example: proxytest.cpp): ";
    }
// PROXY FN END
};
// PROXY END StartingTask

// PROXY BEGIN Main
// PROXY FN BEGIN
int main(int argc, char *argv[]){

    StartingTask st;
    st.printWelcomeMsg();

    char pr_begin[] = "// PROXY BEGIN ";
    int prb = sizeof(pr_begin) / sizeof(pr_begin[0]);

    char pr_end[] = "// PROXY END ";
    int pre = sizeof(pr_end) / sizeof(pr_end[0]);

    char fn_begin[] = "// PROXY FN BEGIN";
    int fnb = sizeof(fn_begin) / sizeof(fn_begin[0]);

    char fn_end[] = "// PROXY FN END";
    int fne = sizeof(fn_end) / sizeof(fn_end[0]);

    ClassWithProxy ca;
    ca.fileHandler(pr_begin, pr_end, fn_begin, fn_end, prb, pre, fnb, fne);

    return 0;
}
// PROXY FN END
// PROXY END Main
