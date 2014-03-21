#include <iostream>
#include <cstdlib>  //랜덤값 생성위한 헤더파일
#include <ctime>    //랜덤값 생성위한 헤더파일.
using namespace std;

struct card
{
	int even_odd;   // 1이면 홀수, 0이면 짝수다.
	int round;      //각 카드가 내어진 라운드를 의미.
	int draw;      // 1이면 아직 안낸 카드, 0이면 낸 카드다.	
};



int main()      
{
	
	int num,num2,j,i;   // num= user card number ,  num2= computer card number  ,   i & j used to   for roop

	int com_score=0, user_score=0;  //user score, computer score
	
	

	struct card com_deck[9];  // 카드 구조체로 이루어진 크기 9짜리 배열 선언. (0~8까지의 배열 숫자를 가지며 0~8까지가 카드의 숫자가 된다.)
	struct card user_deck[9]; // 카드 구조체로 이루어진 크기 9짜리 배열 선언. (0~8까지의 배열 숫자를 가지며 0~8까지가 카드의 숫자가 된다.)

	srand((unsigned int)time(NULL));  //랜덤수 위해서 사용.
	
	for(i=0;i<=8;i++)
	{
		
		com_deck[i].draw=1;         //각 카드 구조체 내부의 draw 를 1, 즉 모두 안낸 카드로 설정.
		com_deck[i].even_odd=i%2;     // i를 2로 나눠서 0이면 짝수   1이면 홀수카드.

		
		user_deck[i].draw=1;		//각 카드 구조체 내부의 draw 를 1, 즉 모두 안낸 카드로 설정.
		user_deck[i].even_odd=i%2;     //0이면 짝수   1이면 홀수카드.
	}

	for(i=0;i<=8;i++)  //i 는 라운드 숫자를 나타낸다. 0~8까지 9라운드를 진행하게 된다.
	{

		for(;;)     //컴퓨터 숫자.
		{
			num2=rand()%9;    //  random number  (컴퓨터의 카드 넘버를 선택해야 하므로 0~8까지의 랜덤수 뽑는다.)

			if(com_deck[num2].draw==1)    // num2 번의 카드구조체의 draw가 0, 즉 낸카드면 다시 뽑고 1이면 안낸카드이므로 for문 탈출.
			break;
		}
		
		if(com_deck[num2].even_odd==0)  //만약 컴퓨터 카드가 짝수라면 even이란 메세지 출력
			cout<<"com : even"<<endl;

		else	//짝수가 아닌 만약 컴퓨터 카드가 홀수라면 odd란 메세지 출력
			cout<<"com : odd"<<endl;

		for(;;)     // 사람 숫자 입력한다.
		{
			cout<<"user : ";
			cin>>num;  //카드 숫자 입력
		

			if(num<0||num>8)  //카드 숫자가 0~8사이만 입력받는다.
			{
				cout<<"0~8사이로 숫자 입력"<<endl;
				continue;
			}

			if(user_deck[num].draw==0)   // 입력한 번째의 카드 구조체의 draw가 0이라면 이미 낸 카드이므로 다시 카드번호 입력.
			cout<<num<<" = 이미 제출한 카드"<<endl;
		
			else if(user_deck[num].draw==1)   //1이라면 아직 내지 않았던 카드이므로 탈출.
			break;
		}

		

		user_deck[num].draw=0;   // 카드 구조체의 draw란 변수에 제출한 카드이므로 draw를 0으로 바꿔준다.
		com_deck[num2].draw=0;   // 컴퓨터껄 바꾼다.
		user_deck[num].round=i;  // 카드 구조체의 round 변수에 i (몇번째 라운드였는지)를 기록.
		com_deck[num2].round=i;  //컴퓨터 카드의 라운드 기록.

		cout<<"----------------------------"<<endl;
		if(num>num2)   //만약 유저가 이겻다면 유저 점수가 오르고 컴퓨터 점수는 내린다.
		{
			cout<<"Winner is User"<<endl;
			user_score=user_score+1;
			com_score=com_score-1;
		}
		else if(num<num2)  //만약 유저가 지면 유저점수가 내리고 컴퓨터 점수는 오른다. 
		{
			cout<<"Winner is Computer"<<endl;
			user_score=user_score-1;
			com_score=com_score+1;
		}
		else
			 cout<<"Draw!!!"<<endl;

		cout<<endl;
	}

		cout<<endl;
		cout<<"result  "<<endl;   //결과 출력한다.
		cout<<"                   user       com"<<endl;
	

		for(i=0;i<=8;i++) //결과 출력.
		{
			for(j=0;j<=8;j++)
			{
				if(user_deck[j].round==i)    //기록했던 카드 구조체의 round변수를 이용해서 1라운드부터 차례대로 냈던 카드를 출력한다.
				{
					cout<<i+1<<" round 결과:      "<<j<<" ";
					break;
				}
			}

			for(j=0;j<=8;j++) ////기록했던 카드 구조체의 round변수를 이용해서 1라운드부터 차례대로 컴퓨터가 냈던 카드를 출력한다.
			{
				if(com_deck[j].round==i)
				{
					cout<<"          "<<j<<" "<<endl;
					break;
				}
			}
		}

		cout<<endl;
		cout<<"user score: "<<user_score<<endl;
		cout<<"com score: "<<com_score<<endl;
		cout<<endl;

		if(user_score>com_score)  //유저가 이겼을 경우
		cout<<"User Victory \n";
	
		else if(user_score<com_score)  //컴퓨터가 이겼을 경우
		cout<<"Computer Victory \n";

		else   //비겼을 때
		cout<<"DRAW!!!!! \n";
		
		


	return 0;

}