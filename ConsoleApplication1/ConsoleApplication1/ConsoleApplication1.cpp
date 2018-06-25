// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class CRenzu;
class CBusiz;
class CJingl;
class CShux
{
public:
	virtual void bdjn() = 0;
	void display();
	void input(int herat, int aggressivity, int defenses);
	void battle(CShux * pk);
	void fbattle(CShux * fpk);
	void dheart(int agg);
	void playzt();
protected:
	int Heart;//生命
	int Aggressivity;//攻击力
	int Counterattack;//反击
	int Defenses;//防御力
	int heart1;//记录生命
};
void CShux::display()
{
	cout << "生命值" << Heart << "攻击力" << Aggressivity << "防御力" << Defenses << endl;
}
void CShux::input(int heart, int aggressivity, int defenses)//给初始值
{
	Heart = heart;
	Aggressivity = aggressivity;
	Defenses = defenses;
	heart1 = Heart;
}
void CShux::dheart(int agg)
{
	if (agg - Defenses > 0)
	{
		Heart -= agg - Defenses;
	}
}
void CShux::battle(CShux * pk)
{
	pk->dheart(Aggressivity);
	pk->fbattle(this);
}
void CShux::fbattle(CShux * fpk)
{
	fpk->dheart(Aggressivity / 2);
}
void CShux::playzt()
{
	cout << "生命值" << Heart << "攻击力" << Aggressivity << "防御力" << Defenses << endl;
}

class CRenzu :public CShux
{
public:
	void bdjn();
private:
	
};
void CRenzu::bdjn()
{
	if (Heart < heart1)
	{
		Defenses += 1;
		heart1 = Heart;
	}
}

class CJingl :public CShux
{
public:
	void bdjn()
	{

	}
private:

};
class CBusiz :public CShux
{
public:
	void bdjn()
	{

	}
private:
};

int main()
{
	CRenzu dns;
	CBusiz clm;
	CJingl xlf;
	dns.input(100, 10, 5);
	clm.input(100, 8, 4);
	xlf.input(100, 8, 2);
	dns.battle(&clm);
	clm.battle(&xlf);
	xlf.battle(&dns);
	dns.playzt();
	clm.playzt();
	xlf.playzt();
	return 0;
}

