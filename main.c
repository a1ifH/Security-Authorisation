#include <stdio.h>
#define size 4

//prototype for access code
int ac_code (int *);

//prototype for encryption of access code
int encryption (int *, int *, int *,int *);

//prototype for decryption of access code
int decryption (int *, int *);

//prototype for printing Successful and failed attempts
void print_succ_fail(int *, int *);

//prototype for exiting program
int end_program(int *);

//start of main
int main ()
{
  //intialising variables
  int option = 0;
  int access_code[size] = { 4, 5, 2, 3 };
  int code1[size];
  int repeat_once=0;
  int repeat_once2=0;
  int input;
  int succ =0;
  int fail =0;
  int end=0;
  int i;

  //start of do while
  do
    {   //menue for user
        printf ("\n\npress 1 to enter access code\n");
        printf ("press 2 to encrypt and verify access code\n");
        printf ("press 3 to decrypt code\n");
        printf ("press 4 to Display if of times the code is encrypted or  decrypted\n");
        printf ("press 5 to exit\n");
        
        //getting input for the menue from user
        scanf("%1s", &option);
        

      switch (option) //start of switch statement
	    {
	        case '1':
	        {   
	            //calling function for input and storing access code
	            ac_code (&code1);
	            break;
	        }//end case 1
	        

	        case '2':
	        {
	            //calling function for encrypting code
	            encryption (&code1, &succ, &fail, &repeat_once); //calling function for increment of successful and faliure
	            break;
	        }//end case 2
	        

	        case '3':
	        {
	            //calling fuction for decrypting code 
	            decryption (&code1, &repeat_once2);
	            break; 
	        }//end case 3
	    

	        case '4':
	        {
	            //calling function to display successful and failed  attempts
	            print_succ_fail (&succ,&fail);
	            break;
	        }//end case 4
	        
	        
	        case '5':
	        {
	            //calling function to end program
	            end_program(&end);
	            break;
	        }//end case 5
	        
	        
	        default:
	        {   
	            //printing 
	            printf("\nerror Try again\n");
	            break;
	        }//end default
	  


	    }//end of switch

    }while (end == 0);//end of do while
 

  return 0;
  
}//end main



//function for input of access code 
int ac_code (int *code)
{
    //intialising variables
    int i;
    
    //asking for user input
    printf ("\nenter access code \n");

    //recieving and storing user input
    for (i = 0; i < size; i++)
      {
        scanf ("%1d", &*code + i);
        
      }//end of for loop
}



//function for encrypting access code
int encryption (int *code, int *succ, int *fail, int *repeat_once)
{
    if(*repeat_once==0)//if statement to stop program from running twice
    {
        *repeat_once=*repeat_once+1;//increments repeat
        
        //intialising varibles
        int count;
        int access_code[size] = { 4, 5, 2, 3 };
        int i;
        int count2;
  
        int var1 = *(code); //var1 is equivalent to 1st number
        int var2 = *(code + 1); //var2 is equivalentto 2nd number

        //swapping 1st number with 3rd number of 
        *(code) = *(code + 2);
  
        //swapping 2nd number with 4th number
        *(code + 1) = *(code + 3);
  
        //swapping 3rd number with 1st number of
        *(code + 2) = var1;
  
        //swapping 4th number with 3rd number of
        *(code + 3) = var2;
  
         //for loop for any number that has a value equal to 10, changes value to 0 
            for (i = 0; i < size; i++)
            {   
                //incrementing code
                *(code + i) = *(code + i) + 1;
        
                //any number that has a value equal to 10, changes value to 0
                if(*(code + i) == 10)
	                {
	                    *(code + i) = 0;
	                }//end if
	        
            }//end for loop
    
    
            //printing encrypted code
            printf ("\nthe encrypted code is:");
            for (i = 0; i < size; i++)
            {
                printf ("%1d", *(code + i));
            }//end for loop
    
     
            //for loop to see if all numbers match
            for (i = 0; i < size; i++)
                {
                    if (*(code + i) == *(access_code + i))//both codes match
	                    {
	                        printf ("\nCode has been encrypted\n");//prints "match" after each matching element
	                        count++;//adds 1 to count
	                        break;
	                    }
	                 else
	                    {
	                        printf ("\nfailed\n");//prints failed after each unmatched element
	                        count2++;//adds 1 to count2
	                    }//end else
	                
                }//end for loop
    
    
    
            if(count == 4)//count equals the 4 matched elements
            {
                *succ=*succ+1;//increments successful
            }//end if
            
            if(count2 <= 1)//count 2 equals any failed elements
            {
                *fail=*fail+1;//increments fail
            }//end if
        
    
    }//end if
    else
    {
        printf("\nalready incrypted\n");//printing statement
    }//end else
  
}//end function


//function for decrypting access code
int decryption (int *code,int *repeat_once2)
{
  if(*repeat_once2==0)//if statement to stop program from running twice
  {
        *repeat_once2=*repeat_once2+1;//increments repeat
        
        //intialising variables
        int i;
        int tmp;

        //for loop for subtracting 1 from each number
        for (i = 0; i < size; i++)
            {
                *(code + i) = *(code + i) - 1;//equation for subtracting 1 from each number
            }// end for loop
            
        
        //for loop for changing value of -1 to 9   
        for (i = 0; i < size; i++)
            {
                if (*(code + i) == -1)
                {                       //equation for changing value of -1 to 9
    	            *(code + i) = 9;
    	        }//end if
            }//end for loop

        //temporary variable is equal to 1st element
        tmp = *(code);
        
        //swapping first element with 3rd element
        *code= *(code+2);
        
        //swapping 3rd element with 1st element
        *(code+2)=tmp;
        
        //swapping 3rd element with 2nd element
        tmp = *(code+1);
        
        //swapping 2nd element with 4th element
        *(code+1)= *(code+3);
        
        //swapping 4th element with 3rd element
        *(code+3)=tmp;
        
        //printing the decryption code
        printf ("\nthe decrypted code is:");
        for (i = 0; i < size; i++)
            {
                printf ("%1d", code[i]);
            }// end for


  }//end if
  else
  {
      printf("\ncode has been already deprypted\n");//printing statement
  }//end else
  
}//end function


//function for printing successful and decrypted code
void print_succ_fail(int *succ, int *fail)
{
    printf("\nyour code has been Successfully encrypted = %d \n", *(succ)); //printing successful encryption
    
    printf("\nyour code has has been decrypted = %d times\n", *(fail)); // printing failed encryption
    
}//end function


//function to end program
int end_program(int *end)
{
    printf("you have exited the program\n");//printing statement
    
    *end=*end+1;//increment end
    
}//end function
