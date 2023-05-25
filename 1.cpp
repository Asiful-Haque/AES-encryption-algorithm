#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define check cout<<"hello"<<endl
#define FASTERIO                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-9
#define PI acos(-1)
#define distance(x1,x2,y1,y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define printvector for(ll i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
#define printmap for(auto it=m.begin();it!=m.end();it++)cout<<it->first<<"-->"<<it->second<<endl;
#define MAX (ll)(2e5+7)
#define arrayzero memset(arr,0,sizeof(arr));
#define s1_is_in_x x.find(s1)!=string::npos
#define mod 1000000007
//ll arr[MAX];
// void sieve(){
//     arr[2]=1;
//     for(ll i=3;i<=MAX;i+=2){
//         arr[i]=1;
//     }
//     for(ll i=3;i<=MAX;i+=2){
//         for(ll j=i*i;j<=MAX;j+=i){
//             arr[j]=0;
//         }
//     }
// }

string arr[4][4]= {{"32","88","31","E0"},
				   {"43","5A","31","37"},
				   {"F6","30","98","07"},
				   {"A8","8D","A2","34"}};

string sBox[16][16]= {
    {"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},
    {"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},
    {"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"},
    {"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},
    {"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"},
    {"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"},
    {"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},
    {"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},
    {"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},
    {"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},
    {"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},
    {"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"},
    {"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},
    {"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"},
    {"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},
    {"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"}
};

string rijendel[4][4]= {{"02","03","01","01"},
					    {"01","02","03","01"},
					    {"01","01","02","03"},
					    {"03","01","01","02"}};

string new_array[4][4];
string subs_array[4][4];

string final_key[4][4]= {{"2B","28","AB","09"},
                         {"7E","AE","F7","CF"},
                         {"15","D2","15","4F"},
                         {"16","A6","88","3C"}};

string final_key_temp_right[4][4]= {{"2B","28","AB","09"},
                                     {"7E","AE","F7","CF"},
                                     {"15","D2","15","4F"},
                                     {"16","A6","88","3C"}};


string RConTable[4][11] = {
        {"00", "01", "02", "04", "08", "10", "20", "40", "80", "1b", "36"},
        {"00", "00", "00", "00", "00", "00", "00", "00", "00", "00", "00"},
        {"00", "00", "00", "00", "00", "00", "00", "00", "00", "00", "00"},
        {"00", "00", "00", "00", "00", "00", "00", "00", "00", "00", "00"}
};
string new1[4][4];

string gf8_addition(vector<string> values) {
    if (values.empty()) {
        return "0";
    }

    unsigned int result = 0;

    for (const string& value : values) {
        unsigned int val;
        stringstream ss;
        ss << hex << value;
        ss >> val;
        result ^= val;
    }

    stringstream result_ss;
    result_ss << hex << uppercase  << setw(2) << setfill('0') << result;
    string result_str = result_ss.str();

    return result_str;
}

// Multiplication operation in GF(2^8)
string gf8_multiplication(string a, string b) {
    unsigned int a_val, b_val;
    stringstream ss;
    ss << hex << a;
    ss >> a_val;
    ss.clear();
    ss << hex << b;
    ss >> b_val;

    unsigned int result = 0;
    while (b_val > 0) {
        if (b_val & 1) {
            result ^= a_val;
        }
        a_val <<= 1;
        if (a_val & 0x100) {
            a_val ^= 0x11B; // XOR with the irreducible polynomial x^8 + x^4 + x^3 + x + 1
        }
        b_val >>= 1;
    }

    stringstream result_ss;
    result_ss << hex << uppercase << result;
    string result_str = result_ss.str();

    return result_str;
}


void subs_array_function(){
	ll first_char,second_char;

	for(ll i=0;i<4;i++){
		for(ll j=0;j<4;j++){
			string s=arr[i][j];
			if(s[0]>='A' && s[0]<='F'){ //for first char
				first_char= s[0]-'A'+1;
				first_char+=9;
			}
			else{
				first_char= s[0]-'0';
			}

			if(s[1]>='A' && s[1]<='F'){ //for second char
				second_char= s[1]-'A'+1;
				second_char+=9;
			}
			else{
				second_char= s[1]-'0';
			}

			subs_array[i][j]=sBox[first_char][second_char];
		}
	}

	// cout<<"Substituted Array :"<<endl;
	// for(ll i=0;i<4;i++){
 //    	for(ll j=0;j<4;j++){
 //    		cout<<subs_array[i][j]<<" ";
 //    	}
 //    	cout<<endl;
 //    }
 //    cout<<endl;
}
void shift_row_function(){
	string temp1,temp2,temp3;

	temp1=subs_array[1][0];      //2nd row shift
	subs_array[1][0]=subs_array[1][1];
	subs_array[1][1]=subs_array[1][2];
	subs_array[1][2]=subs_array[1][3];
	subs_array[1][3]=temp1;

	temp1=subs_array[2][0];      //3rd row shift
	temp2=subs_array[2][1];
	subs_array[2][0]=subs_array[2][2];
	subs_array[2][1]=subs_array[2][3];
	subs_array[2][2]=temp1;
	subs_array[2][3]=temp2;

	temp1=subs_array[3][0];      //4rth row shift
	temp2=subs_array[3][1];
	temp3=subs_array[3][2];
	subs_array[3][0]=subs_array[3][3];
	subs_array[3][1]=temp1;
	subs_array[3][2]=temp2;
	subs_array[3][3]=temp3;

	// cout<<"Shifted Array :"<<endl;
 //    for(ll i=0;i<4;i++){
 //    	for(ll j=0;j<4;j++){
 //    		cout<<subs_array[i][j]<<" ";
 //    	}
 //    	cout<<endl;
 //    }
 //    cout<<endl;
}

void mixed_colum_function(){
	vector<string>v;
	// string one=gf8_multiplication();
	for(ll i=0;i<4;i++){
		for(ll j=0;j<4;j++){
			for(ll k=0;k<4;k++){
				v.push_back(gf8_multiplication(rijendel[i][k],subs_array[k][j]));
			}
			new_array[i][j] = gf8_addition(v);
			// printvector;
			v.clear();
		}
	}
	
	// cout<<"Mixed Array :"<<endl;
	// for(ll i=0;i<4;i++){
 //    	for(ll j=0;j<4;j++){
 //    		cout<<new_array[i][j]<<" ";
 //    	}
 //    	cout<<endl;
 //    }
 //    cout<<endl;

}

void add_round_key_function_initial(){

	cout<<"Plain Text :"<<endl;
	for(ll i=0;i<4;i++){
    	for(ll j=0;j<4;j++){
    		cout<<arr[i][j]<<" ";
    	}
    	cout<<endl;
    }
    cout<<endl;

    cout<<"Initial key :"<<endl;
	for(ll i=0;i<4;i++){
    	for(ll j=0;j<4;j++){
    		cout<<final_key[i][j]<<" ";
    	}
    	cout<<endl;
    }
    cout<<endl;

	for(ll i=0;i<4;i++){
		for(ll j=0;j<4;j++){
			stringstream ss1(final_key[i][j]);
            stringstream ss2(arr[i][j]);

            ll num1, num2;
            ss1 >> hex >> num1;
            ss2 >> hex >> num2;

            ll result = num1 ^ num2;
            
            stringstream ss;
            ss << hex << uppercase<< setw(2) << setfill('0') << result;
            string xorResult = ss.str();
            arr[i][j]=xorResult;
		}
	}

	cout<<"initial text of round 1"<<endl;
	for(ll i=0;i<4;i++){
		for(ll j=0;j<4;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void add_round_key_function(ll round){

	string temp = final_key[0][3];
        final_key_temp_right[0][3] = final_key[1][3];
        final_key_temp_right[1][3] = final_key[2][3];
        final_key_temp_right[2][3] = final_key[3][3];
        final_key_temp_right[3][3] = temp;

        
        ll j=3;                  /////////substitution
        for(ll i=0;i<4;i++){
            ll first_char,second_char;

            string s=final_key_temp_right[i][j];

            if(s[0]>='A' && s[0]<='F'){ //for first char
                first_char= s[0]-'A'+1;
                first_char+=9;
            }
            else{
                first_char= s[0]-'0';
            }

            if(s[1]>='A' && s[1]<='F'){ //for second char
                second_char= s[1]-'A'+1;
                second_char+=9;
            }
            else{
                second_char= s[1]-'0';
            }

            final_key_temp_right[i][j]=sBox[first_char][second_char];
        }


        for(ll j=0;j<4;j++){        //////taking new array

            stringstream ss1(final_key_temp_right[j][3]);
            stringstream ss2(final_key[j][0]);
            stringstream ss3(RConTable[j][round]);

            ll num1, num2 ,num3;
            ss1 >> hex >> num1;
            ss2 >> hex >> num2;
            ss3 >> hex >> num3;

            ll result = num1 ^ num2 ^ num3;
            
            stringstream ss;
            ss << hex << uppercase << setw(2) << setfill('0') << result;
            string xorResult = ss.str();

            new1[j][0]=xorResult;            //////taking new array

            
        }  


        for(ll i=1;i<4;i++){       //rest of the columns.
            for(ll j=0;j<4;j++){
                stringstream ss1(final_key[j][i]);
                stringstream ss2(new1[j][i-1]);

                ll num1, num2;
                ss1 >> hex >> num1;
                ss2 >> hex >> num2;
                ll result = num1 ^ num2;

                stringstream ss;
                ss << hex << uppercase << setw(2) << setfill('0') << result;
                string xorResult = ss.str();

                new1[j][i]=xorResult; 

            }
        }

        // cout<<"Rest columns"<<endl;
        // for(ll i=0;i<4;i++){
        //     for(ll j=0;j<4;j++){
        //         cout<<new1[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(ll i=0;i<4;i++){
            for(ll j=0;j<4;j++){
                stringstream ss1(new1[i][j]);
                stringstream ss2(new_array[i][j]);

                ll num1, num2;
                ss1 >> hex >> num1;
                ss2 >> hex >> num2;
                ll result = num1 ^ num2;

                stringstream ss;
                ss << hex << uppercase<< setw(2) << setfill('0')  << result;
                string xorResult = ss.str();
 
                arr[i][j] = xorResult;
            }
        }

        for(ll i=0;i<4;i++){
            for(ll j=0;j<4;j++){
                final_key[i][j]=new1[i][j];
            }
        }

        // cout<<"text for next round "<<round<<endl;
        // for(ll i=0;i<4;i++){
        //     for(ll j=0;j<4;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        cout<<"Key for next round "<<round<<endl;
        for(ll i=0;i<4;i++){
            for(ll j=0;j<4;j++){
                cout<<final_key[i][j]<<" ";
            }
            cout<<endl;
        }  
        cout<<endl;

        if(round==10){cout<<"Encrypted Message"<<endl;}
        else{cout<<"text for round "<<round+1<<endl;}
        for(ll i=0;i<4;i++){
            for(ll j=0;j<4;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
        for(ll i=0;i<4;i++){
            for(ll j=0;j<4;j++){
                new1[i][j]="";
            }
        }

}

int main(){
	add_round_key_function_initial();
	for(ll round=1;round<=9;round++){
		subs_array_function();
		shift_row_function();
		mixed_colum_function();
		add_round_key_function(round);
	}
	subs_array_function();
	shift_row_function();
    add_round_key_function(10);



}

// for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             for (int k = 0; k < 4; k++) {
				//	v.push_back(A[i][k] * B[k][j]);
//                 
//             }
               //C[i][j] = addition(v);
               //v.clear();
//         }
//     }
