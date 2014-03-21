#include <iostream>
#include <cstdlib>  //������ �������� �������
#include <ctime>    //������ �������� �������.
using namespace std;

struct card
{
	int even_odd;   // 1�̸� Ȧ��, 0�̸� ¦����.
	int round;      //�� ī�尡 ������ ���带 �ǹ�.
	int draw;      // 1�̸� ���� �ȳ� ī��, 0�̸� �� ī���.	
};



int main()      
{
	
	int num,num2,j,i;   // num= user card number ,  num2= computer card number  ,   i & j used to   for roop

	int com_score=0, user_score=0;  //user score, computer score
	
	

	struct card com_deck[9];  // ī�� ����ü�� �̷���� ũ�� 9¥�� �迭 ����. (0~8������ �迭 ���ڸ� ������ 0~8������ ī���� ���ڰ� �ȴ�.)
	struct card user_deck[9]; // ī�� ����ü�� �̷���� ũ�� 9¥�� �迭 ����. (0~8������ �迭 ���ڸ� ������ 0~8������ ī���� ���ڰ� �ȴ�.)

	srand((unsigned int)time(NULL));  //������ ���ؼ� ���.
	
	for(i=0;i<=8;i++)
	{
		
		com_deck[i].draw=1;         //�� ī�� ����ü ������ draw �� 1, �� ��� �ȳ� ī��� ����.
		com_deck[i].even_odd=i%2;     // i�� 2�� ������ 0�̸� ¦��   1�̸� Ȧ��ī��.

		
		user_deck[i].draw=1;		//�� ī�� ����ü ������ draw �� 1, �� ��� �ȳ� ī��� ����.
		user_deck[i].even_odd=i%2;     //0�̸� ¦��   1�̸� Ȧ��ī��.
	}

	for(i=0;i<=8;i++)  //i �� ���� ���ڸ� ��Ÿ����. 0~8���� 9���带 �����ϰ� �ȴ�.
	{

		for(;;)     //��ǻ�� ����.
		{
			num2=rand()%9;    //  random number  (��ǻ���� ī�� �ѹ��� �����ؾ� �ϹǷ� 0~8������ ������ �̴´�.)

			if(com_deck[num2].draw==1)    // num2 ���� ī�屸��ü�� draw�� 0, �� ��ī��� �ٽ� �̰� 1�̸� �ȳ�ī���̹Ƿ� for�� Ż��.
			break;
		}
		
		if(com_deck[num2].even_odd==0)  //���� ��ǻ�� ī�尡 ¦����� even�̶� �޼��� ���
			cout<<"com : even"<<endl;

		else	//¦���� �ƴ� ���� ��ǻ�� ī�尡 Ȧ����� odd�� �޼��� ���
			cout<<"com : odd"<<endl;

		for(;;)     // ��� ���� �Է��Ѵ�.
		{
			cout<<"user : ";
			cin>>num;  //ī�� ���� �Է�
		

			if(num<0||num>8)  //ī�� ���ڰ� 0~8���̸� �Է¹޴´�.
			{
				cout<<"0~8���̷� ���� �Է�"<<endl;
				continue;
			}

			if(user_deck[num].draw==0)   // �Է��� ��°�� ī�� ����ü�� draw�� 0�̶�� �̹� �� ī���̹Ƿ� �ٽ� ī���ȣ �Է�.
			cout<<num<<" = �̹� ������ ī��"<<endl;
		
			else if(user_deck[num].draw==1)   //1�̶�� ���� ���� �ʾҴ� ī���̹Ƿ� Ż��.
			break;
		}

		

		user_deck[num].draw=0;   // ī�� ����ü�� draw�� ������ ������ ī���̹Ƿ� draw�� 0���� �ٲ��ش�.
		com_deck[num2].draw=0;   // ��ǻ�Ͳ� �ٲ۴�.
		user_deck[num].round=i;  // ī�� ����ü�� round ������ i (���° ���忴����)�� ���.
		com_deck[num2].round=i;  //��ǻ�� ī���� ���� ���.

		cout<<"----------------------------"<<endl;
		if(num>num2)   //���� ������ �̰�ٸ� ���� ������ ������ ��ǻ�� ������ ������.
		{
			cout<<"Winner is User"<<endl;
			user_score=user_score+1;
			com_score=com_score-1;
		}
		else if(num<num2)  //���� ������ ���� ���������� ������ ��ǻ�� ������ ������. 
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
		cout<<"result  "<<endl;   //��� ����Ѵ�.
		cout<<"                   user       com"<<endl;
	

		for(i=0;i<=8;i++) //��� ���.
		{
			for(j=0;j<=8;j++)
			{
				if(user_deck[j].round==i)    //����ߴ� ī�� ����ü�� round������ �̿��ؼ� 1������� ���ʴ�� �´� ī�带 ����Ѵ�.
				{
					cout<<i+1<<" round ���:      "<<j<<" ";
					break;
				}
			}

			for(j=0;j<=8;j++) ////����ߴ� ī�� ����ü�� round������ �̿��ؼ� 1������� ���ʴ�� ��ǻ�Ͱ� �´� ī�带 ����Ѵ�.
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

		if(user_score>com_score)  //������ �̰��� ���
		cout<<"User Victory \n";
	
		else if(user_score<com_score)  //��ǻ�Ͱ� �̰��� ���
		cout<<"Computer Victory \n";

		else   //����� ��
		cout<<"DRAW!!!!! \n";
		
		


	return 0;

}