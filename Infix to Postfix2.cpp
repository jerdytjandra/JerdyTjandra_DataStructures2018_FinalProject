#include<iostream>
#include<vector>

using namespace std;

// Determines the priority of the scanned operator
int level(char e)
{
    if(e == '^')
    	return 4;
    else if(e == '/')
    	return 3;
    else if(e == '*')
    	return 2;
    else if(e == '+' || e == '-')
    	return 1;
    else
    	return 0;
}

// Function to converts Infix input to Postfix output
void infixToPostfix(string InFix)
{
    vector<char> storage; //Array to store scanned operators
	storage.push_back('N');
    int s = InFix.length();
    string PostFix; //Output string
    
    for(int i = 0; i < s; i++)
    {
    	cout << "Token from InFix: "<< InFix[i] << endl;
		cout << "PostFix string: "<< PostFix << endl;
		cout << "Operator storage: ";
		for(int k=0; k<storage.size(); ++k)
  			cout << storage[k] << ' ';
    	cout << endl;
    	
        // If the scanned character is an operand, add it to output string.
        if(isdigit(InFix[i]) || isalpha(InFix[i])){
        	PostFix+=InFix[i];
        	cout << "Add " << InFix[i] << " to Postfix string\n" << endl;
		}
 
        // If the scanned character is an ‘(‘, push_back_back it to the array.
        else if(InFix[i] == '('){
        	storage.push_back('(');
        	cout << "Push " << InFix[i] << " to storage\n" << endl;
		}
         
        // If the scanned character is an ‘)’, pop_back and to output string from the array
        // until an ‘(‘ is encountered.
        else if(InFix[i] == ')')
        {
            while(storage.back() != 'N' && storage.back() != '(')
            {
                char e = storage.back();
                storage.pop_back();
        		PostFix += e;
        		cout << "Pop " << e << " to PostFix string\n" << endl;
            }
            if(storage.back() == '(')
            {
                char e = storage.back();
                storage.pop_back();
        		cout << "Pop " << e << " from storage\n" << endl;
            }
        }
         
        //If an operator is scanned
        else{
            while(storage.back() != 'N' && level(InFix[i]) <= level(storage.back()))
            {
                char e = storage.back();
                storage.pop_back();
                PostFix += e;
            }
            storage.push_back(InFix[i]);
        	cout << "Push " << InFix[i] << " to storage\n" << endl;
        }
    }
    
    //Pop all the remaining elements from the array into output string
    while(storage.back() != 'N')
    {
        char e = storage.back();
        storage.pop_back();
        PostFix += e;
    }
    cout << "in InFix notation: " << InFix << "\nin PostFix notation: " << PostFix << endl << endl;
}
 
//Driver program to test above functionPostFix
int main()
{
	string InFix;
	string loop;
	
	while(true)
	{
		cout << "Do You Want To Run The Program (y/n) ?\n>";
		cin >> loop;
		system("cls");
		
		if (loop == "y")
		{
			cout << "Enter an arithmetic expression in infix notation\n>";
		    cin >> InFix;
			system("cls");
		    infixToPostfix(InFix);
		}
		
		else if (loop == "n")
		{
			cout << "Program ended" << endl;
			break;
		}
		
		else
			cout << "Please Type In Either 'y' or 'n' Only..." << endl;
	}	
}
