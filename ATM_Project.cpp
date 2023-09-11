#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class User{
// private:
    
public:
	vector<float>balance{0, 0, 0, 0, 0};
    vector<string>user_names{"Shailesh Madne","Prathmesh Waydande","Abhishek Kakad","Mrigesh Palav","Shrinivas Bhosale"};
    vector<int> Account_number{86543219, 67847368, 99746734, 47636834, 36458325};
    
    string getName(int index)
    {
        return user_names[index];
    }
    
    int get_balance(int index)
    {
        // to return the account number related to 
        return balance[index];
    }
    
};

class ATM{

private:
    
    // defining object of user class
    User u;
	vector<int>PIN{5678 , 986055, 8624, 7865, 6754}; // can be 4 or 6 digits
	int valid_index; // to make changes with correct account holder

public:
    
    bool valid_pin(int pin)
    {
        
        // digit count should be either 6 or 4 pin valid hone ke liye
        int digit_count = 0;
        
        while(pin!=0){
            digit_count++;
            pin = pin/10;
        }
        
        //cout << digit_count << endl;
        if(digit_count == 4 || digit_count == 6){
            return true;
        } else {
            return false;
        }
    }
     // check pin function 
	void check_pin()
	{
		int entered_pin;
		cout << "Enter your pin: ";
		cin >> entered_pin;
// 		int valid_index = -1;
		if(valid_pin(entered_pin)){
		    // pin is either 4 digit / 6 digit then its valid
		    // again checking entered_pin if it is present in PIN or not
    		bool Incorrect_pin = true;
    		for(int i = 0 ; i<5 ; ++i)
    		{
    			if(entered_pin == PIN[i])
    			{
    			    valid_index = i;
    				Incorrect_pin = false;
    			}
    		}
        		
        	if(Incorrect_pin == true)
        	{
    		    cout << "Wrong pin entered!" << endl;
    		    check_pin();
    		} else {
    		  cout << "You have entered correct pin" << endl;
    		  menu();
    		}
		}
		else
		{
		    // enter valid PIN
		    cout << "Enter a valid pin!" << endl;
		    // call check_pin() again
		    check_pin();
		}
		
	}
    
    void menu()
    {
        cout << "Enter Your Choice: " <<endl;
        cout << "1. Check Account Balance" << " " << "2. Details of Account holder" << endl;
        cout << "3. Deposit Money " << " " << "4. Withdraw Money" << endl;
        cout << "5. Change PIN " << "    " << "6. Exit" << endl;
        int opt;
        while(1)
        {
             cin >> opt;
            switch(opt)
            {
                case 2:
                    // check_pin();
                    get_account_details();
                    menu();
                    break;
                case 1:
                    // check_pin();
                    check_balance();
                    menu();
                    break;
                case 3:
                    // check_pin();
                    Deposit();
                    menu();
                    break;
                case 4:
                    // check_pin();
                    Withdraw();
                    menu();
                    break;
                case 5:
                    // check_pin();
                    ChangePIN();
                    break;
                case 6:
                    // 40
                    cout << "---------------------------------------- Thank you for using XYZ ATM!  ----------------------------------------" << endl;
                    exit(0);
                default:
                    cout << "Enter a valid choice!" << endl;
                    menu();
                    break;
            }
        }
    }


    void get_account_details(){
        // get the name , Available Balance
        
        cout << "Name of Account holder : " << u.getName(valid_index) << endl;
        cout << "           Avail. Balance: " << u.get_balance(valid_index) << endl;
    }
	
	// check Balance
	void check_balance(){
	    cout << "Avail. Balance: " << u.balance[valid_index] << endl;
	    menu();
	}
	
	// Withdraw money
	void Withdraw(){
	    float Withdrawl_amount;
	    cout << "Enter withdrawl amount: ";
	    cin >> Withdrawl_amount;
	    
	    if(Withdrawl_amount > u.balance[valid_index])
	    {
	        cout << "Insufficient Balance" << endl;
	    }
	    else
	    {
	        u.balance[valid_index] = u.balance[valid_index] - Withdrawl_amount;
	        cout << "Money withdrawl successfully!" << endl;
	       // cout << "Avail balance: " << balance << endl;
	    }
	    // goes back to main menu
	    menu();
	   return ;
	}
	
	// deposit money
	void Deposit(){
	    float deposit_amount;
	    cout << "Enter deposit amount: ";
	    cin >> deposit_amount;
	    u.balance[valid_index] = u.balance[valid_index] + deposit_amount;
	    cout << "Money deposited successfully!" << endl;
	   // menu();
	    return ;
	}
	
	
	void ChangePIN(int index){
	    // this is for changing the new pin with existing
	    int new_pin;
        cout << "Enter new pin: ";
        cin >> new_pin;
        
        if(valid_pin(new_pin)){
            PIN[index] = new_pin; // change the existing pin
            // cout << PIN[index] << endl;
            cout << "PIN changed successfully!" << endl;
        } else {
            cout << "Entered pin is Invalid!" << endl;
            ChangePIN(index);
        }
	}
	
	// change pin - change the existing pin
	void ChangePIN(){
	    int existing_pin;
	    cout << "Enter existing pin: ";
	    cin >> existing_pin;
	    
	     /* 
	        changing the existing pin and print - changed successfully!
	        
	        before checking the existing pin is present or not 
	        first check for the existing pin entered is valid or not
	    */
	    if(valid_pin(existing_pin))
	    {
	        // existing_pin entered is valid now procceed further
    	    bool res = false;
    	    int index = -1;
    	    for(int i = 0 ; i<PIN.size() ; i++)
    	    {
    	        if(PIN[i] == existing_pin)
    	        {
    	            valid_index = i; // store index of existing_pin
    	            res = true;
    	        }
    	    }
    	    
    
    	    if(res == false)
    	    {
    	        // if entered pin is not present then wrong pin entered
    	        cout << "Wrong pin entered!" << endl;
    	        ChangePIN();
    	    } 
    	    else 
    	    {
        	        // if existing_pin is present 
        	        ChangePIN(valid_index);
    	    }
    	}
	    else
	    {
	        // entered existing pin is not valid
	        cout << "Existing pin entered is Invalid!" << endl;
	            ChangePIN();
	    }
	    // goes back to menu
	    menu();
	    return ;
	}

	
};




int main()
{
    ATM atm;
    cout << "---------------------------------------- Welcome to XYZ ATM! ----------------------------------------" << endl;
    atm.check_pin();
	return 0;
}
