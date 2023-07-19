#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
using namespace std;
struct thing
{
    string type;
    string name;
    int attack;
    int defense;
    int health;
    int num;
    bool disposable;
    int sharp;
    int durability;
};
struct w
{
    string name;
    string b[100];
    int bnum;
};
int health = 1000, maxhealth = 1000, defense = 10, attack = 100;
int capacity = 0;
string name;
int nowway = 0, water = 0, maxwater = 10;
int bagi = 1, protectlevel;
string protect;
string canmakething[1000] = { "退出","木剑","木斧","木镐","工作台" };
int canmakethingi = 5;
string f[100] = {
    {"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"},
    {"+..................................................................................................+"},
    {"+..................................................................................................+"},
    {"+.........+............................................K...........................................+"},
    {"+.......FV+........................................................................................+"},
    {"+...................F..........T...................................................................+"},
    {"+........+................+.............+.............V.......................CF...................+"},
    {"+.......+..........................................................................................+"},
    {"+.............................................................+.H.+..............B.................+"},
    {"+......F.......+.......+............V............................+.................................+"},
    {"+...............V....+...............................................................Y.............+"},
    {"+....................F+.......+++............++....................................................+"},
    {"+.............................+C+.......o....I+.....o...................S..........F...............+"},
    {"+..........................................+++.....................................................+"},
    {"+.............................+.........................V..........................................+"},
    {"+.........Y...........H......+..........o.......+..A...........+...................................+"},
    {"+...........................+..................o+............++....G..............YV...............+"},
    {"+.....................................................+......+.I...................................+"},
    {"+......................+++.......................+++..........+....................................+"},
    {"+.....................+..U+......................V........+....+.............Y.....................+"},
    {"+.......H...........++...++........................................................................+"},
    {"+.......................+Y................++...................M...................................+"},
    {"+......................................+...G+...........T..........................................+"},
    {"+...H..............W............................................................Y..................+"},
    {"+..................................................................................................+"},
    {"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"},
};
bool isf[100][100];
int movex[4] = { 0,-1,0,1 };
int movey[4] = { -1,0,1,0 };

//H巨坑 I铁矿 C煤矿 G金矿 o小镇 Y城市 V洞穴 S飞船 F战场 M沼泽 T钛矿 P前哨 B硫磺矿 K军事基地
int Outpostx[100], opxi = 0;
int Outposty[100], opyi = 0;
w way[100] = {
    {"池塘",{"进入森林","背包","状态","装备","制作"}, 5},
    {"帮助&设置",{"制造配方"},1}
};
int waynum = 2;
bool isw[100] = { true, false, false };
bool isb[100] = { true, false, false };
thing nowaxe, nowpickaxe, nowweapon, nowhoe;
thing bag[1000] = {
    {"退出","退出",0,0,0,0,false},
};
string outbutton()
{
    char c;
    int now = 0;
    for (int i = 0; i < 100; i++)
    {
        if (isb[i] == true)
        {
            now = i;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; way[i].name != ""; i++)
        {
            if (isw[i] == true)
            {
                cout << "*" << way[i].name << "*";
            }
            else
            {
                cout << " " << way[i].name << " ";
            }
        }
        cout << endl;
        for (int i = 0; way[nowway].b[i] != ""; i++)
        {
            if (isb[i] == true)
            {
                cout << ">" << way[nowway].b[i] << "<" << endl;
            }
            else
            {
                cout << " " << way[nowway].b[i] << " " << endl;
            }
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isb[now] = false;
            isb[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && way[nowway].b[now + 1] != "")
        {
            isb[now] = false;
            isb[now + 1] = true;
            now += 1;
        }
        if (c == 'a' && nowway > 0)
        {
            isw[nowway] = false;
            isw[nowway - 1] = true;
            nowway -= 1;
            isb[now] = false;
            isb[0] = true;
        }
        if (c == 'd' && way[nowway + 1].name != "")
        {
            isw[nowway] = false;
            isw[nowway + 1] = true;
            nowway += 1;
            isb[now] = false;
            isb[0] = true;
        }
        if (c == 32)
        {
            return way[nowway].b[now];
        }
    }
    return "";
}
string outbag()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    while (1)
    {
        system("cls");
        for (int i = 0; bag[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag[i].name << "<";
            }
            else
            {
                cout << " " << bag[i].name << " ";
            }
            for (int j = 0; j < 20 - bag[i].name.size() - to_string(bag[i].num).size(); j++)
            {
                cout << " ";
            }
            cout << bag[i].num << "    " << bag[i].durability << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            return bag[now].name;
        }
    }
    return 0;
}
bool skills[10];//勘察术 美食家 矿工 收集家 野蛮人 战士 铠甲人 医生 忍者   原作者已弃坑这一部分内容的制作 
int fight(string hn, int hmh, int ha, int hd, int hh)
{
    while (1)
    {
        if (nowweapon.type == "剑") cout << "1,扎刺";
        else if (nowweapon.type == "刀") cout << "1,劈砍";
        else if (nowweapon.type == "机枪") cout << "1,扫射";
        else if (nowweapon.type == "手枪") cout << "1,射击";
        else if (nowweapon.type == "") cout << "1,拳击";
        bool is1 = false, is2 = false, is3 = false;
        int i1, i2, i3;
        for (int i = 0; i < 1000; i++)
        {
            if (bag[i].name == "手雷" && bag[i].num != 0)
            {
                cout << " 2,丢出[" << bag[i].num << "]";
                is1 = true;
                i1 = i;
                break;
            }
        }
        for (int i = 0; i < 1000; i++)
        {
            if (bag[i].name == "长矛" && bag[i].num != 0)
            {
                cout << " 3,投掷[" << bag[i].num << "]";
                is2 = true;
                i2 = i;
                break;
            }
        }
        for (int i = 0; i < 1000; i++)
        {
            if (bag[i].name == "熏肉" && bag[i].num != 0)
            {
                cout << " 4,吃肉[" << bag[i].num << "]";
                is3 = true;
                i3 = i;
                break;
            }
        }
        if (skills[7])
        {
            cout << "5,医治";
        }
        string which;
        cin >> which;
        int bullet = 0, missile = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (bag[i].name == "子弹")
            {
                bullet = bag[i].num;
            }
            if (bag[i].name == "导弹")
            {
                missile = bag[i].num;
            }
            else if (bag[i].name == "")
            {
                break;
            }
        }
        if (which == "1")
        {
            if (nowweapon.type == "剑" || nowweapon.type == "刀" || nowweapon.type == "")
            {
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "] @       E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]  @      E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]   @     E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]    @    E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]     @   E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]      @  E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]       @ E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]        @E[" << hh << "/" << hmh << "]";
                if (skills[5]) hh -= (attack + nowweapon.attack) * 2 - hd;
                else hh -= attack + nowweapon.attack - hd;
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]      @  E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]    @    E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]  @      E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            }
            else if (nowweapon.name == "激光步枪" || bullet > 0 || (nowweapon.name == "火箭筒" && missile > 0))
            {
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@o       E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@ o      E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@  o     E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@   o    E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@    o   E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@     o  E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@      o E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@       oE[" << hh << "/" << hmh << "]";
                if (skills[5]) hh -= (attack + nowweapon.attack) * 2 - hd;
                else hh -= attack + nowweapon.attack - hd;
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            }
            else if (bullet <= 0 || (nowweapon.name == "火箭筒" && missile <= 0))
            {
                MessageBox(0, TEXT("没弹药了..."), TEXT("重要提示"), MB_OK);
            }
        }
        else if (which == "2" && is1)
        {
            hh -= 500;
            system("cls");
            cout << "砰！";
            Sleep(1000);
            system("cls");
            cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            bag[i1].num--;
        }
        else if (which == "3" && is2)
        {
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@>       E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@->      E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@ ->     E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@  ->    E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@   ->   E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@    ->  E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@     -> E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@      ->E[" << hh << "/" << hmh << "]";
            hh -= 200 - hd;
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            bag[i2].num--;
        }
        else if (which == "4" && is3)
        {
            if (skills[2])
            {
                cout << "生命+1000";
                health += 1000;
                if (health > maxhealth)
                {
                    health = maxhealth;
                }
            }
            else
            {
                cout << "生命+500";
                health += 500;
                if (health > maxhealth)
                {
                    health = maxhealth;
                }
            }
            bag[is3].num--;
        }
        else if (which == "5" && skills[7])
        {
            cout << "生命+1500";
            health += 1500;
            if (health > maxhealth)
            {
                health = maxhealth;
            }
        }
        if (hh <= 0)
        {
            cout << "对方死亡";
            Sleep(1000);
            return 1;
        }
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@       E [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@      E  [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@     E   [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@    E    [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@   E     [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@  E      [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@ E       [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@E        [" << hh << "/" << hmh << "]";
        if (skills[8])
        {
            if (rand() % 3 == 2) health -= ha + -defense;
        }
        else if (rand() % 2) health -= ha + -defense;
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@  E      [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@    E    [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@      E  [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
        Sleep(1000);
        cout << endl;
        if (health <= 0)
        {
            cout << "你死亡";
            Sleep(1000);
            return 0;
        }
    }
    return 0;
}
void slowly(const char* p)
{
    while (1)
    {
        if (*p != 0)
        {
            printf("%c", *p++);
        }
        else
        {
            break;
        }
        Sleep(30);
    }
}
int welcome()
{
    cout << "野外生存1.1.0 (不支持存档)" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "         本页面会持续更新...   " << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    _getch();
    return 0;
}
int start()
{
    system("cls");
    cout << "□□□□□□■□□□□□□□□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□■■□□□□□□□□□□□□□□□□□■□□" << endl;
    cout << "□□□□□□■■■□□□□□□□□□□□□□□□■■□□" << endl;
    cout << "□□□■■■■■■■■■■■■■■■□□□□■■■■□□" << endl;
    cout << "□□■□■□■□■□■□■□■□■□■■■■■■■■□□" << endl;
    cout << "□□□■■■■■■■■■■■■■■■■■■■■■■□□□" << endl;
    cout << "□□□□□□□□■■■■■□□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□■■■■■□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□■■■□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□■■■□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□□■■■□□□□□□□□□□□□" << endl;
    slowly("一天，你坐着飞机，正打算去美国...");
    Sleep(1000);
    system("cls");
    cout << "□□□□□□■□□□□□□□□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□■■□□□□□□□□□□□□□□□□□■□□" << endl;
    cout << "□□□□□□■■■□□□□□□□□□□□□□□□■■□□" << endl;
    cout << "□□□■■■■■■■■■■■■■■■□□□□■■■■□□" << endl;
    cout << "□□■□■□■□■□■□■□■□■□■■■■■■■■□□" << endl;
    cout << "□□□■■■■■■■■■■■■■■■■■■■■■■□□□" << endl;
    cout << "□□□□□□□□■■■■■□□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□■■■■■□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□■■■□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□■■■□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□□■■■□□□□□□□□□□□□" << endl;
    slowly("一边看着电影，一边喝着饮料");
    Sleep(1000);
    system("cls");
    cout << "□□□□□□■□□□□□□□□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□■■□□□□□□□□□□□□□□□□□■□□" << endl;
    cout << "□□□□□□■■■□□□□□□□□□□□□□□□■■□□" << endl;
    cout << "□□□■■■■■■■■■■■■■■■□□□□■■■■□□" << endl;
    cout << "□□■□■□■□■□■□■□■□■□■■■■■■■■□□" << endl;
    cout << "□□□■■■■■■■■■■■■■■■■■■■■■■□□□" << endl;
    cout << "□□□□□□□□■■■■■□□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□■■■■■□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□■■■□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□■■■□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□□■■■□□□□□□□□□□□□" << endl;
    slowly("突然，飞机开始颠簸，你手中饮料摔到了地上，洒了一地");
    Sleep(1000);
    system("cls");
    cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□■■■■□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□■■■■■■■■□□□□□□□□□□□" << endl;
    cout << "□□□□■■■■■■□□■■□□■■■■■■□□□□□□" << endl;
    cout << "□□□□□□□□□■■■■■■■■□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□■■■■■■□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□■■□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
    slowly("一秒钟后，飞机开始往下坠落");
    Sleep(1000);
    system("cls");
    cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□■■■■□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□■■■■■■■■□□□□□□□□□□□" << endl;
    cout << "□□□□■■■■■■□□■■□□■■■■■■□□□□□□" << endl;
    cout << "□□□□□□□□□■■■■■■■■□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□■■■■■■□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□■■□□□□□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
    slowly("行李架上的行李掉了下来，砸中了你，你眼前一黑，昏了过去...");
    Sleep(1000);
    system("cls");
    Sleep(3000);
    slowly("醒来后，你发现你躺在一个池塘边，靠着石头。");
    _getch();
    return 0;
}
bool isinto = false;
int town(int y, int x)
{
    system("cls");
    cout << " ___小镇_______" << endl;
    cout << "|是否进入      |" << endl;
    cout << "|(y/n)         |" << endl;
    cout << "|______________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "一个村民手拿大刀，拦在了入口处" << endl;
        _getch();
        if (!fight("村民", 1000, 100, 10, 1000))
        {
            system("cls");
            slowly("眼前的世界烟消云散...");
            Sleep(1000);
            return 0;
        }
        system("cls");
        int xunrou = rand() % 3, changmao = rand() % 2, rou = rand() % 5;
        cout << "掉落：" << endl;
        cout << "1,熏肉*" << xunrou << endl;
        cout << "2,肉*" << rou << endl;
        cout << "3,长矛*" << changmao << endl;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "熏肉")
            {
                bag[j].num += xunrou;
                break;
            }
            if (bag[j].name == "" && xunrou != 0)
            {
                bag[j] = { "食物","熏肉",0,0,0,xunrou,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "肉")
            {
                bag[j].num += rou;
                break;
            }
            if (bag[j].name == "" && rou != 0)
            {
                bag[j] = { "食物","肉",0,0,0,rou,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "长矛")
            {
                bag[j].num += changmao;
                break;
            }
            if (bag[j].name == "" && changmao != 0)
            {
                bag[j] = { "武器","长矛",0,0,0,changmao,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        cout << "另一个村民手拿着长矛，跑了过来" << endl;
        _getch();
        if (!fight("村民", 1000, 100, 10, 1000))
        {
            system("cls");
            slowly("眼前的世界烟消云散...");
            Sleep(1000);
            return 0;
        }
        int pimao = rand() % 3, buliao = rand() % 5;
        rou = rand() % 5;
        cout << "掉落：" << endl;
        cout << "1,皮毛*" << pimao << endl;
        cout << "2,肉*" << rou << endl;
        cout << "3,布料*" << changmao << endl;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "皮毛")
            {
                bag[j].num += pimao;
                break;
            }
            if (bag[j].name == "" && pimao != 0)
            {
                bag[j] = { "物品","皮毛",0,0,0,pimao,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "肉")
            {
                bag[j].num += rou;
                break;
            }
            if (bag[j].name == "" && rou != 0)
            {
                bag[j] = { "食物","肉",0,0,0,rou,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "布料")
            {
                bag[j].num += buliao;
                break;
            }
            if (bag[j].name == "" && buliao != 0)
            {
                bag[j] = { "物品","布料",0,0,0,buliao,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        cout << "安静下来了" << endl;
        _getch();
        pimao = rand() % 3; buliao = rand() % 5; rou = rand() % 5;
        cout << "获得：" << endl;
        cout << "1,皮毛*" << pimao << endl;
        cout << "2,肉*" << rou << endl;
        cout << "3,布料*" << changmao << endl;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "皮毛")
            {
                bag[j].num += pimao;
                break;
            }
            if (bag[j].name == "")
            {
                bag[j] = { "物品","皮毛",0,0,0,pimao,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "肉")
            {
                bag[j].num += rou;
                break;
            }
            if (bag[j].name == "")
            {
                bag[j] = { "食物","肉",0,0,0,rou,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "布料")
            {
                bag[j].num += buliao;
                break;
            }
            if (bag[j].name == "")
            {
                bag[j] = { "物品","布料",0,0,0,buliao,false,0 };
                break;
            }
        }
        _getch();
        slowly("你离开了小镇...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
        return 1;
    }
    else if (c != 'n')
    {
        town(y, x);
    }
    return 1;
}
int hole(int y, int x)
{
    system("cls");
    cout << " __巨坑_______" << endl;
    cout << "|是否进入      |" << endl;
    cout << "|(y/n)         |" << endl;
    cout << "|______________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "外星人举起了枪..." << endl;
        _getch();
        fight("外星人", 10000, 1000, 100, 10000);
        int waixinghejin = rand() % 3 + 1, taihejin = rand() % 5 + 1, jiguangbuqiang = rand() % 3 + 1;
        cout << "掉落：" << endl;
        cout << "1,外星合金*" << waixinghejin << endl;
        cout << "2,钛合金*" << taihejin << endl;
        cout << "3,激光步枪*" << jiguangbuqiang << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "外星合金")
            {
                isfind = true;
                bag[j].num += waixinghejin;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "材料","外星合金",0,0,0,waixinghejin,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "钛合金")
            {
                isfind = true;
                bag[j].num += taihejin;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "材料","钛合金",0,0,0,taihejin,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "激光步枪")
            {
                isfind = true;
                bag[j].num += jiguangbuqiang;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "武器","激光步枪",0,0,0,jiguangbuqiang,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        slowly("你离开了巨坑...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        hole(y, x);
    }
    return 0;
}
int iron(int y, int x)
{
    system("cls");
    cout << " ___铁矿_______" << endl;
    cout << "|是否进入      |" << endl;
    cout << "|(y/n)        |" << endl;
    cout << "|_____________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "野兽来袭..." << endl;
        _getch();
        fight("野兽", 5000, 500, 50, 5000);
        int tie = rand() % 3 + 1;
        cout << "掉落：" << endl;
        cout << "1,铁*" << tie << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "铁")
            {
                isfind = true;
                bag[j].num += tie;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "材料","铁",0,0,0,tie,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            if (way[i].name == "挖矿之路")
            {
                way[i].b[way[i].bnum++] = "挖铁矿";
                break;
            }
            if (way[i].name == "")
            {
                way[waynum++] = { "挖矿之路",{"挖铁矿"},1 };
                break;
            }
        }
        slowly("你离开了铁矿...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        iron(y, x);
    }
    return 0;
}
int coal(int y, int x)
{
    system("cls");
    cout << " ___煤矿_______" << endl;
    cout << "|是否进入      |" << endl;
    cout << "|(y/n)        |" << endl;
    cout << "|_____________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "野兽来袭..." << endl;
        _getch();
        fight("野兽", 7000, 300, 100, 7000);
        int mei = rand() % 3 + 1;
        cout << "掉落：" << endl;
        cout << "1,煤*" << mei << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "煤")
            {
                isfind = true;
                bag[j].num += mei;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "材料","煤",0,0,0,mei,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            if (way[i].name == "挖矿之路")
            {
                way[i].b[way[i].bnum++] = "挖煤矿";
                break;
            }
            if (way[i].name == "")
            {
                way[waynum++] = { "挖矿之路",{"挖煤矿"},1 };
                break;
            }
        }
        slowly("你离开了煤矿...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        coal(y, x);
    }
    return 0;
}
int gold(int y, int x)
{
    system("cls");
    cout << " ___金矿_______" << endl;
    cout << "|是否进入      |" << endl;
    cout << "|(y/n)        |" << endl;
    cout << "|_____________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "野兽来袭..." << endl;
        _getch();
        fight("野兽", 10000, 500, 70, 10000);
        int mei = rand() % 3 + 1;
        cout << "掉落：" << endl;
        cout << "1,金*" << mei << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "金")
            {
                isfind = true;
                bag[j].num += mei;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "材料","金",0,0,0,mei,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            if (way[i].name == "挖矿之路")
            {
                way[i].b[way[i].bnum++] = "挖金矿";
                break;
            }
            if (way[i].name == "")
            {
                way[waynum++] = { "挖矿之路",{"挖金矿"},1 };
                break;
            }
        }
        slowly("你离开了金矿...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        coal(y, x);
    }
    return 0;
}
int brenstone(int y, int x)
{
    system("cls");
    cout << " ___硫磺矿_____" << endl;
    cout << "|是否进入      |" << endl;
    cout << "|(y/n)        |" << endl;
    cout << "|_____________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "野兽来袭..." << endl;
        _getch();
        fight("野兽", 10000, 800, 10, 10000);
        int mei = rand() % 3 + 1;
        cout << "掉落：" << endl;
        cout << "1,硫磺*" << mei << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "硫磺")
            {
                isfind = true;
                bag[j].num += mei;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "材料","硫磺",0,0,0,mei,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            if (way[i].name == "挖矿之路")
            {
                way[i].b[way[i].bnum++] = "挖硫磺矿";
                break;
            }
            if (way[i].name == "")
            {
                way[waynum++] = { "挖矿之路",{"挖硫磺矿"},1 };
                break;
            }
        }
        slowly("你离开了金矿...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        coal(y, x);
    }
    return 0;
}
int forest()
{
    int x = 51, y = 14;
    char c;
    for (int i = 0; i < opxi; i++) f[Outposty[i]][Outpostx[i]] = 'P';
    while (1)
    {
        system("cls");
        cout << "水:" << water << "/" << maxwater << endl;
        f[y][x] = '@';
        if (skills[0])
        {
            isf[y + 3][x] = true;
            isf[y + 2][x + 1] = true; isf[y + 2][x] = true;     isf[y + 2][x - 1] = true;
            isf[y + 1][x + 2] = true; isf[y + 1][x + 1] = true; isf[y + 1][x] = true;     isf[y + 1][x - 1] = true; isf[y + 1][x - 2] = true;
            isf[y][x + 3] = true;     isf[y][x + 2] = true;     isf[y][x + 1] = true; isf[y][x] = true;     isf[y][x - 1] = true; isf[y][x - 2] = true; isf[y][x - 3] = true;
            isf[y - 1][x + 2] = true; isf[y - 1][x + 1] = true; isf[y - 1][x] = true;     isf[y - 1][x - 1] = true; isf[y - 1][x - 2] = true;
            isf[y - 2][x + 1] = true; isf[y - 2][x] = true;     isf[y - 2][x - 1] = true;
            isf[y - 3][x] = true;
        }
        else
        {
            isf[y + 2][x] = true;
            isf[y + 1][x + 1] = true; isf[y + 1][x] = true; isf[y + 1][x - 1] = true;
            isf[y][x + 2] = true;     isf[y][x + 1] = true; isf[y][x]; isf[y][x] = true; isf[y][x - 1] = true; isf[y][x - 2] = true;
            isf[y - 1][x + 1] = true; isf[y - 1][x] = true; isf[y - 1][x - 1] = true;
            isf[y - 2][x] = true;
        }
        for (int i = y - 20; i < y + 20; i++)
        {
            if (i < 0 || i > 25)
            {
                continue;
            }
            for (int j = x - 20; j < x + 20; j++)
            {
                if (j >= 0 && j <= 100)
                {
                    if (isf[i][j])
                    {
                        cout << f[i][j];
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
        c = _getch();
        water--;
        if (water == 0) MessageBox(0, TEXT("水喝完了"), TEXT("重要提示"), MB_OK);
        if (water == -1) MessageBox(0, TEXT("你感觉口干舌燥"), TEXT("重要提示"), MB_OK);
        if (water == -2)
        {
            MessageBox(0, TEXT("你倒在森林里..."), TEXT("重要提示"), MB_OK);
            system("cls");
            slowly("眼前的世界烟消云散...");
            Sleep(1000);
            f[y][x] = '.';
            return 0;
        }
        int move = 4;
        if (c == 'w')move = 0;
        if (c == 'a')move = 1;
        if (c == 's')move = 2;
        if (c == 'd')move = 3;
        if (move == 4)
        {
            continue;
        }
        if (f[y + movey[move]][x + movex[move]] == 'o')
        {
            if (!town(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'H')
        {
            if (!hole(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'I')
        {
            if (!iron(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'C')
        {
            if (!coal(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'G')
        {
            if (!gold(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'P')
        {
            f[y + movey[move]][x + movex[move]] = '@';
            f[y][x] = '.';
            y += movey[move];
            x += movex[move];
            MessageBox(0, TEXT("水补充好了"), TEXT("前方哨所"), MB_OK);
            water = maxwater;
            MessageBox(0, TEXT("熏肉+7"), TEXT("前方哨所"), MB_OK);
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "熏肉")
                {
                    bag[j].num += 7;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "食物","熏肉",0,0,0,7,false,0 };
                    break;
                }
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'U')
        {
            slowly("你来到了一个村庄，是时候享用那些人留下的成绩了...");
            int jiguangbuqiang, shoulai, daodan, zidan, buqiang, gang, tie, mei, waixinghejin, taihejin, huojiantong;
            jiguangbuqiang = rand() % 2 + 1; shoulai = rand() % 3 + 2; daodan = rand() % 3 + 1;
            zidan = rand() % 50 + 50; buqiang = rand() % 5 + 1; waixinghejin = rand() % 5 + 5;
            tie = rand() % 10 + 10; mei = rand() % 10 + 10; gang = rand() % 10 + 10;
            taihejin = rand() % 10 + 10, huojiantong = rand() % 2 + 1;
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "激光步枪")
                {
                    bag[j].num += jiguangbuqiang;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "机枪","激光步枪",1000,0,0,jiguangbuqiang,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "手雷")
                {
                    bag[j].num += shoulai;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "武器","手雷",0,0,0,shoulai,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "导弹")
                {
                    bag[j].num += daodan;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "武器","导弹",0,0,0,daodan,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "子弹")
                {
                    bag[j].num += zidan;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "武器","子弹",0,0,0,zidan,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "火箭筒")
                {
                    bag[j].num += huojiantong;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "机枪","火箭筒",700,0,0,huojiantong,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "步枪")
                {
                    bag[j].num += buqiang;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "机枪","步枪",300,0,0,buqiang,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "钢")
                {
                    bag[j].num += gang;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "材料","钢",0,0,0,gang,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "铁")
                {
                    bag[j].num += tie;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "材料","铁",0,0,0,tie,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "煤")
                {
                    bag[j].num += mei;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "材料","煤",0,0,0,mei,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "外星合金")
                {
                    bag[j].num += waixinghejin;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "材料","外星合金",0,0,0,waixinghejin,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "钛合金")
                {
                    bag[j].num += taihejin;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "材料","钛合金",0,0,0,taihejin,false,0 };
                    break;
                }
            }
            MessageBox(0, TEXT("你看着这些东西，突然觉悟"), TEXT("你"), MB_OK);
            MessageBox(0, TEXT("我能造出更多东西了"), TEXT("你"), MB_OK);
            canmakething[canmakethingi++] = "钢";
            canmakething[canmakethingi++] = "精铁";
            canmakething[canmakethingi++] = "钢刀";
            canmakething[canmakethingi++] = "钢剑";
            canmakething[canmakethingi++] = "钢镐";
            canmakething[canmakethingi++] = "钢斧";
            canmakething[canmakethingi++] = "铁刀";
            canmakething[canmakethingi++] = "精铁剑";
            canmakething[canmakethingi++] = "精铁镐";
            canmakething[canmakethingi++] = "精铁斧";
            canmakething[canmakethingi++] = "强·石斧";
            canmakething[canmakethingi++] = "强·石剑";
            canmakething[canmakethingi++] = "强·石镐";
            canmakething[canmakethingi++] = "木锄";
            canmakething[canmakethingi++] = "石锄";
            canmakething[canmakethingi++] = "铁锄";
            canmakething[canmakethingi++] = "工作室";
            _getch();
        }
        if (f[y + movey[move]][x + movex[move]] == 'A')
        {
            f[y][x] = '.';
            return 0;
        }
        if (f[y + movey[move]][x + movex[move]] == '.')
        {
            f[y][x] = '.';
            f[y + movey[move]][x + movex[move]] = '@';
            y += movey[move];
            x += movex[move];
        }
    }
    return 0;
}
int weapon()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    thing bag2[1000];
    int bag2i = 0;
    for (int i = 0; bag[i].name != ""; i++)
    {
        if (bag[i].type == "剑" || bag[i].type == "刀" || bag[i].type == "手枪" || bag[i].type == "机枪")
        {
            bag2[bag2i] = bag[i];
            bag2i++;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; bag2[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag2[i].name << "<";
            }
            else
            {
                cout << " " << bag2[i].name << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag2[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            nowweapon = bag2[now];
            return 0;
        }
    }
    return 0;
}
int tool_axe()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    thing bag2[1000];
    int bag2i = 0;
    for (int i = 0; bag[i].name != ""; i++)
    {
        if (bag[i].type == "斧头" && bag[i].num > 0)
        {
            bag2[bag2i] = bag[i];
            bag2i++;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; bag2[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag2[i].name << "<";
            }
            else
            {
                cout << " " << bag2[i].name << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag2[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            nowaxe = bag2[now];
            return 0;
        }
    }
    return 0;
}
int tool_pickaxe()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    thing bag2[1000];
    int bag2i = 0;
    for (int i = 0; bag[i].name != ""; i++)
    {
        if (bag[i].type == "镐" && bag[i].num > 0)
        {
            bag2[bag2i] = bag[i];
            bag2i++;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; bag2[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag2[i].name << "<";
            }
            else
            {
                cout << " " << bag2[i].name << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag2[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            nowpickaxe = bag2[now];
            return 0;
        }
    }
    return 0;
}
int tool_hoe()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    thing bag2[1000];
    int bag2i = 0;
    for (int i = 0; bag[i].name != ""; i++)
    {
        if (bag[i].type == "锄" && bag[i].num > 0)
        {
            bag2[bag2i] = bag[i];
            bag2i++;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; bag2[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag2[i].name << "<";
            }
            else
            {
                cout << " " << bag2[i].name << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag2[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            nowhoe = bag2[now];
            return 0;
        }
    }
    return 0;
}
string make()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    while (1)
    {
        system("cls");
        for (int i = 0; i < canmakethingi; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << canmakething[i] << "<";
            }
            else
            {
                cout << " " << canmakething[i] << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && canmakething[now + 1] != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            return canmakething[now];
        }
    }
    return 0;
}
int make(string thi[100], int num[100], thing makething)
{
    bool all = true;
    for (int i = 0; thi[i] != ""; i++)
    {
        for (int j = 0; bag[j].name != ""; j++)
        {
            if (bag[j].name == thi[i])
            {
                all &= bag[j].num >= num[i];
            }
        }
    }
    if (all)
    {
        for (int i = 0; thi[i] != ""; i++)
        {
            for (int j = 0; bag[j].name != ""; j++)
            {
                if (bag[j].name == thi[i])
                {
                    bag[j].num -= num[i];
                }
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == makething.name)
            {
                bag[j].num++;
                break;
            }
            if (bag[j].name == "")
            {
                bag[j] = makething;
                break;
            }
        }
        cout << "制作成功" << endl;
        return 1;
    }
    else
    {
        cout << "材料不够..." << endl;
        return 0;
    }
    return 0;
}
int main()
{
    srand((unsigned)time(NULL));
    welcome();
    start();
    while (1)
    {
        string a = outbutton();
        if (a == "进入森林")
        {
            system("cls");
            water = maxwater;
            if (isinto == false)
            {
                isinto = true;
                slowly("你进入森林，慢慢走着，竟发现了一个完好的斧头，躺在一块巨岩上");
                cout << endl;
                slowly("你拿起斧头，仔细端详一番，发现这斧头竟是崭新的！");
                cout << endl;
                cout << "\t你获得了一把木斧";
                bag[bagi++] = { "斧头","木斧",10,1,0,1,false,10,20 };
                _getch();
                cout << endl;
                slowly("你把斧头带走了...");
                Sleep(1000);
                way[0].b[way[0].bnum++] = "伐木";
            }
            else
            {
                slowly("你进入森林");
                forest();
            }
        }
        else if (a == "背包")
        {
            system("cls");
            outbag();
        }
        else if (a == "状态")
        {
            system("cls");
            cout << "生命:" << health << "/" << maxhealth << endl;
            cout << "防御：" << defense;
            cout << "攻击" << attack << "+" << nowweapon.attack << "(" << attack + nowweapon.attack << ")" << endl;
            cout << "装备武器：";
            if (nowweapon.name != "") cout << nowweapon.name;
            else cout << "未装备";
            cout << "     剩余耐久：" << nowweapon.durability << endl;
            cout << "装备斧头：";
            if (nowaxe.name != "") cout << nowaxe.name;
            else cout << "未装备";
            cout << "     剩余耐久：" << nowaxe.durability << endl;
            cout << "装备镐：";
            if (nowpickaxe.name != "") cout << nowpickaxe.name;
            else cout << "未装备";
            cout << "     剩余耐久：" << nowpickaxe.durability << endl;
            cout << "装备锄：";
            if (nowhoe.name != "") cout << nowhoe.name;
            else cout << "未装备";
            cout << "     剩余耐久：" << nowhoe.durability << endl;
            _getch();
        }
        else if (a == "伐木")
        {
            if (nowaxe.name == "")
            {
                cout << "你未装备着斧头...";
                Sleep(1000);
            }
            else
            {
                int ran = rand() % 100;
                if (ran < 9)
                {
                    cout << "你遇到了野兽" << endl;
                    _getch();
                    fight("野兽", 3000, 50, 5, 3000);

                }
                else
                {
                    ran = rand() % 7 + 3;
                    cout << "林地上散落着枯枝败叶" << endl;
                    Sleep((rand() % 10000 + 10000) / nowaxe.sharp);
                    cout << "树上掉下来了几根树枝" << endl;
                    Sleep((rand() % 10000 + 10000) / nowaxe.sharp);
                    cout << "森林里躺着一棵大树" << endl;
                    Sleep((rand() % 10000 + 10000) / nowaxe.sharp);
                    cout << "\t你获得了" << ran << "根木头！" << endl;
                    _getch();
                    nowaxe.durability -= 1;
                    if (nowaxe.durability <= 0)
                    {
                        cout << "但很不幸，你的木斧断了..." << endl;
                        cout << "\t你少了一把斧头" << endl;
                        for (int i = 0; i < 1000; i++)
                        {
                            if (bag[i].name == nowaxe.name)
                            {
                                bag[i].num--;
                                break;
                            }
                        }
                        nowaxe = {};
                        _getch();
                    }
                    for (int i = 0; i < 1000; i++)
                    {
                        if (bag[i].name == "木头")
                        {
                            bag[i].num += ran;
                            break;
                        }
                        if (bag[i].name == "")
                        {
                            bag[i] = { "材料","木头",0,0,0,ran,false };
                            break;
                        }
                    }
                }
            }
        }
        else if (a == "装备")
        {
            system("cls");
            cout << " _请选择____________________________________________" << endl;
            cout << "|0，退出 1，武器 2，伐木工具 3，挖矿工具 4，种地工具|" << endl;
            cout << "|___________________________________________________|" << endl;
            string x;
            cin >> x;
            if (x == "1")weapon();
            if (x == "2")tool_axe();
            if (x == "3")tool_pickaxe();
            if (x == "4")tool_hoe();
        }
        else if (a == "制作")
        {
            string t = make();
            if (t == "木剑")
            {
                string thi[100] = { "木头","" };
                int num[100] = { 50,0 };
                thing makething = { "剑","木剑",50,0,0,1,false,10,20 };
                make(thi, num, makething);
            }
            else if (t == "木斧")
            {
                string thi[100] = { "木头","" };
                int num[100] = { 50,0 };
                thing makething = { "斧头","木斧",0,0,0,1,false,10,20 };
                make(thi, num, makething);
            }
            else if (t == "木镐")
            {
                string thi[100] = { "木头","" };
                int num[100] = { 50,0 };
                thing makething = { "镐","木镐",0,0,0,1,false,10,20 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                            break;
                        }
                    }
                }
            }
            else if (t == "工作台")
            {
                string thi[100] = { "木头","" };
                int num[100] = { 100,0 };
                thing makething = { "物品","工作台",0,0,0,1,false,0,100 };
                if (make(thi, num, makething))
                {
                    canmakething[canmakethingi++] = "陷阱";
                    canmakething[canmakethingi++] = "长矛";
                    canmakething[canmakethingi++] = "木刀";
                    canmakething[canmakethingi++] = "水袋[容量20]";
                    canmakething[canmakethingi++] = "石斧";
                    canmakething[canmakethingi++] = "石镐";
                    canmakething[canmakethingi++] = "石剑";
                    canmakething[canmakethingi++] = "木材";
                    canmakething[canmakethingi++] = "小屋";
                    canmakething[canmakethingi++] = "皮革室";
                }
            }
            else if (t == "陷阱")
            {
                string thi[100] = { "木头","" };
                int num[100] = { 100,0 };
                thing makething = { "物品","陷阱",0,0,0,1,false,0,100 };
                if (make(thi, num, makething))
                {
                    way[waynum++] = { "森林",{"查看陷阱"},1 };
                }
            }
            else if (t == "石剑")
            {
                string thi[100] = { "木头","石头" };
                int num[100] = { 30,50 };
                thing makething = { "剑","石剑",100,0,0,1,false,0,50 };
                make(thi, num, makething);
            }
            else if (t == "石斧")
            {
                string thi[100] = { "木头","石头" };
                int num[100] = { 30,50 };
                thing makething = { "斧头","石斧",0,0,0,1,false,20,50 };
                make(thi, num, makething);
            }
            else if (t == "石镐")
            {
                string thi[100] = { "木头","石头" };
                int num[100] = { 30,50 };
                thing makething = { "镐","石镐",0,0,0,1,false,20,50 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "长矛")
            {
                string thi[100] = { "木头","石头" };
                int num[100] = { 10,20 };
                thing makething = { "武器","长矛",0,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "水袋[容量20]")
            {
                string thi[100] = { "木头","皮毛" };
                int num[100] = { 5,50 };
                thing makething = { "水袋","水袋",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    if (maxwater < 20)
                    {
                        maxwater = 20;
                    }
                }
            }
            else if (t == "木刀")
            {
                string thi[100] = { "木头","" };
                int num[100] = { 60,0 };
                thing makething = { "刀","木刀",75,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "木甲")
            {
                string thi[100] = { "木头","皮革" };
                int num[100] = { 60,45 };
                thing makething = { "甲","木甲",0,20,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "木材")
            {
                string thi[100] = { "木头" };
                int num[100] = { 10 };
                thing makething = { "材料","木材",0,0,0,5,false,0,0 };
                make(thi, num, makething);
            }
            else if (t == "皮革室")
            {
                string thi[100] = { "木头","木材","石头","" };
                int num[100] = { 200,100,100,0,0 };
                thing makething = { "房间","皮革室",0,0,0,1,false,0,0 };
                if (make(thi, num, makething))
                {
                    MessageBox(0, TEXT("有皮革了..."), TEXT("你"), MB_OK);
                    way[waynum++] = { "皮革室",{"制造皮革",},1 };
                }
            }
            else if (t == "小屋")
            {
                string thi[100] = { "木头","木材","石头","皮革","" };
                int num[100] = { 200,100,100,75,0 };
                thing makething = { "房间","小屋",0,0,0,1,false,0,0 };
                if (make(thi, num, makething))
                {
                    MessageBox(0, TEXT("终于有个可以休息的地方了..."), TEXT("你"), MB_OK);
                    MessageBox(0, TEXT("我可以造一些更好的东西了..."), TEXT("你"), MB_OK);
                    way[waynum++] = { "小屋",{"添柴",},1 };
                    canmakething[canmakethingi++] = "岩石";
                    canmakething[canmakethingi++] = "石刀";
                    canmakething[canmakethingi++] = "精·石剑";
                    canmakething[canmakethingi++] = "精·石斧";
                    canmakething[canmakethingi++] = "精·石剑";
                    canmakething[canmakethingi++] = "铁剑";
                    canmakething[canmakethingi++] = "铁斧";
                    canmakething[canmakethingi++] = "铁剑";
                    canmakething[canmakethingi++] = "客舍";
                    canmakething[canmakethingi++] = "水桶[容量30]";
                    canmakething[canmakethingi++] = "熏肉房";
                }
            }
            else if (t == "岩石")
            {
                string thi[100] = { "石头" };
                int num[100] = { 15,0 };
                thing makething = { "材料","岩石",0,0,0,5,false,0,0 };
                make(thi, num, makething);
            }
            else if (t == "精·石剑")
            {
                string thi[100] = { "木头","岩石" };
                int num[100] = { 100,50 };
                thing makething = { "剑","精·石剑",160,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "精·石斧")
            {
                string thi[100] = { "木头","岩石" };
                int num[100] = { 100,50 };
                thing makething = { "斧头","精·石斧",0,0,0,1,false,30,100 };
                make(thi, num, makething);
            }
            else if (t == "精·石镐")
            {
                string thi[100] = { "木头","岩石" };
                int num[100] = { 100,50 };
                thing makething = { "镐","精·石镐",0,0,0,1,false,30,100 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "精·长矛")
            {
                string thi[100] = { "木头","石头" };
                int num[100] = { 5,10 };
                thing makething = { "武器","长矛",0,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "铁剑")
            {
                string thi[100] = { "木头","铁" };
                int num[100] = { 200,50 };
                thing makething = { "剑","铁剑",200,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "铁斧")
            {
                string thi[100] = { "木头","铁" };
                int num[100] = { 200,50 };
                thing makething = { "斧头","铁斧",0,0,0,1,false,50,150 };
                make(thi, num, makething);
            }
            else if (t == "铁镐")
            {
                string thi[100] = { "木头","铁" };
                int num[100] = { 200,50 };
                thing makething = { "镐","铁镐",0,0,0,1,false,50,150 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "石刀")
            {
                string thi[100] = { "木头","岩石" };
                int num[100] = { 30,30 };
                thing makething = { "刀","石刀",130,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "铁刀")
            {
                string thi[100] = { "木头","铁" };
                int num[100] = { 100,50 };
                thing makething = { "刀","铁刀",180,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "钢刀")
            {
                string thi[100] = { "木头","钢" };
                int num[100] = { 100,50 };
                thing makething = { "刀","钢刀",230,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "水桶[容量30]")
            {
                string thi[100] = { "木材","皮毛","岩石" };
                int num[100] = { 50,50,100 };
                thing makething = { "水袋","水桶",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    if (maxwater < 30)
                    {
                        maxwater = 30;
                    }
                }
            }
            else if (t == "熏肉房")
            {
                string thi[100] = { "木材","皮毛","岩石" };
                int num[100] = { 100,50,100 };
                thing makething = { "房间","熏肉房",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    MessageBox(0, TEXT("好吃的熏肉，可以自制了"), TEXT("你"), MB_OK);
                    way[nowway++] = { "熏肉房",{"做熏肉"},1 };
                }
            }
            else if (t == "强·石剑")
            {
                string thi[100] = { "木材","岩石" };
                int num[100] = { 100,50 };
                thing makething = { "剑","强·石剑",250,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "强·石斧")
            {
                string thi[100] = { "木材","岩石" };
                int num[100] = { 100,50 };
                thing makething = { "斧头","强·石斧",0,0,0,1,false,40,120 };
                make(thi, num, makething);
            }
            else if (t == "强·石镐")
            {
                string thi[100] = { "木材","岩石" };
                int num[100] = { 100,50 };
                thing makething = { "镐","强·石镐",0,0,0,1,false,40,120 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "钢剑")
            {
                string thi[100] = { "木头","钢" };
                int num[100] = { 100,50 };
                thing makething = { "剑","钢剑",300,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "钢斧")
            {
                string thi[100] = { "木头","钢" };
                int num[100] = { 100,50 };
                thing makething = { "斧头","钢斧",0,0,0,1,false,60,160 };
                make(thi, num, makething);
            }
            else if (t == "钢镐")
            {
                string thi[100] = { "木头","钢" };
                int num[100] = { 100,50 };
                thing makething = { "镐","钢镐",0,0,0,1,false,60,160 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "钢")
            {
                string thi[100] = { "铁","煤" };
                int num[100] = { 10,10 };
                thing makething = { "材料","钢",0,0,0,5,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "精铁剑")
            {
                string thi[100] = { "木头","精铁" };
                int num[100] = { 200,50 };
                thing makething = { "剑","精铁剑",250,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "精铁斧")
            {
                string thi[100] = { "木头","精铁" };
                int num[100] = { 200,50 };
                thing makething = { "斧头","精铁斧",0,0,0,1,false,60,150 };
                make(thi, num, makething);
            }
            else if (t == "精铁镐")
            {
                string thi[100] = { "木头","精铁" };
                int num[100] = { 200,50 };
                thing makething = { "镐","精铁镐",0,0,0,1,false,60,150 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "木锄")
            {
                string thi[100] = { "木头","" };
                int num[100] = { 50,0 };
                thing makething = { "锄","木锄",0,0,0,1,false,10,20 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "种菜")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "种菜";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "石锄")
            {
                string thi[100] = { "木头","石头" };
                int num[100] = { 20,50 };
                thing makething = { "锄","石锄",0,0,0,1,false,20,50 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "种菜")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "种菜";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "铁锄")
            {
                string thi[100] = { "木头","铁" };
                int num[100] = { 20,50 };
                thing makething = { "锄","铁锄",0,0,0,1,false,30,100 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "种菜")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "种菜";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "精铁")
            {
                string thi[100] = { "铁","" };
                int num[100] = { 10 };
                thing makething = { "材料","精铁",0,0,0,4,false,30,100 };
            }
            else if (t == "大水桶[容量40]")
            {
                string thi[100] = { "木材","皮毛","岩石" };
                int num[100] = { 100,100,100 };
                thing makething = { "水袋","大水桶",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    if (maxwater < 40)
                    {
                        maxwater = 40;
                    }
                }
            }
            else if (t == "工作室")
            {
                string thi[100] = { "木材","皮革","岩石" };
                int num[100] = { 300,300,300 };
                thing makething = { "物品","工作室",0,0,0,1,false,0,200 };
                if (make(thi, num, makething))
                {
                    MessageBox(0, TEXT("终于能好好做一些东西了..."), TEXT("你"), MB_OK);
                    canmakething[canmakethingi++] = "子弹";
                    canmakething[canmakethingi++] = "手枪";
                    canmakething[canmakethingi++] = "金子";
                    canmakething[canmakethingi++] = "水箱[容量50]";
                    canmakething[canmakethingi++] = "锋利·铁剑";
                    canmakething[canmakethingi++] = "锋利·铁镐";
                    canmakething[canmakethingi++] = "锋利·铁斧";
                    canmakething[canmakethingi++] = "耐久·铁镐";
                    canmakething[canmakethingi++] = "耐久·铁斧";
                    canmakething[canmakethingi++] = "锋利·耐久·铁镐";
                    canmakething[canmakethingi++] = "锋利·耐久·铁斧";
                    canmakething[canmakethingi++] = "锋利·钢剑";
                    canmakething[canmakethingi++] = "锋利·钢镐";
                    canmakething[canmakethingi++] = "锋利·钢斧";
                    canmakething[canmakethingi++] = "耐久·钢镐";
                    canmakething[canmakethingi++] = "耐久·钢斧";
                    canmakething[canmakethingi++] = "锋利·耐久·钢镐";
                    canmakething[canmakethingi++] = "锋利·耐久·钢斧";
                    canmakething[canmakethingi++] = "制造室";
                    canmakething[canmakethingi++] = "钉子";
                    canmakething[canmakethingi++] = "钢合金";
                }
            }
            else if (t == "钉子")
            {
                string thi[100] = { "铁" };
                int num[100] = { 1 };
                thing makething = { "材料","钉子",0,0,0,2,false,0,0 };
                make(thi, num, makething);
            }
            else if (t == "子弹")
            {
                string thi[100] = { "钢","硫磺" };
                int num[100] = { 10,10 };
                thing makething = { "弹药","子弹",0,0,0,10,true,0,1 };
                make(thi, num, makething);
            }
            else if (t == "手枪")
            {
                string thi[100] = { "钢","铁" };
                int num[100] = { 100,100 };
                thing makething = { "手枪","手枪",500,0,0,1,false,0,1 };
                make(thi, num, makething);
            }
            else if (t == "金子")
            {
                string thi[100] = { "金","" };
                int num[100] = { 1 };
                thing makething = { "钱","金子",0,0,0,10,false,0,1 };
                make(thi, num, makething);
            }
            else if (t == "水箱[容量50]")
            {
                string thi[100] = { "木材","皮毛","岩石","钉子" };
                int num[100] = { 100,100,100,50 };
                thing makething = { "水袋","水箱",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    if (maxwater < 50)
                    {
                        maxwater = 50;
                    }
                }
            }
            else if (t == "锋利·铁剑")
            {
                string thi[100] = { "铁剑","精铁" };
                int num[100] = { 1,50 };
                thing makething = { "剑","锋利·铁剑",350,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "锋利·铁斧")
            {
                string thi[100] = { "铁斧","精铁" };
                int num[100] = { 1,50 };
                thing makething = { "斧头","锋利·铁斧",0,0,0,1,false,70,150 };
                make(thi, num, makething);
            }
            else if (t == "锋利·铁镐")
            {
                string thi[100] = { "铁镐","精铁" };
                int num[100] = { 1,50 };
                thing makething = { "镐","锋利·铁镐",0,0,0,1,false,70,150 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "耐久·铁斧")
            {
                string thi[100] = { "铁斧","铁" };
                int num[100] = { 1,100 };
                thing makething = { "斧头","耐久·铁斧",0,0,0,1,false,60,200 };
                make(thi, num, makething);
            }
            else if (t == "耐久·铁镐")
            {
                string thi[100] = { "铁镐","铁" };
                int num[100] = { 1,100 };
                thing makething = { "镐","耐久·铁镐",0,0,0,1,false,60,200 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "锋利·耐久·铁斧")
            {
                string thi[100] = { "耐久·铁斧","精铁" };
                int num[100] = { 1,50 };
                thing makething = { "斧头","锋利·耐久·铁斧",0,0,0,1,false,70,200 };
                make(thi, num, makething);
            }
            else if (t == "锋利·耐久·铁镐")
            {
                string thi[100] = { "耐久·铁镐","精铁" };
                int num[100] = { 1,50 };
                thing makething = { "镐","锋利·耐久·铁镐",0,0,0,1,false,70,200 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "锋利·钢剑")
            {
                string thi[100] = { "钢剑","钢合金" };
                int num[100] = { 1,50 };
                thing makething = { "剑","锋利·钢剑",400,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "锋利·钢斧")
            {
                string thi[100] = { "钢斧","钢合金" };
                int num[100] = { 1,50 };
                thing makething = { "斧头","锋利·钢斧",0,0,0,1,false,80,150 };
                make(thi, num, makething);
            }
            else if (t == "锋利·钢镐")
            {
                string thi[100] = { "钢镐","钢合金" };
                int num[100] = { 1,50 };
                thing makething = { "镐","锋利·钢镐",0,0,0,1,false,80,150 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "耐久·钢斧")
            {
                string thi[100] = { "钢斧","钢" };
                int num[100] = { 1,100 };
                thing makething = { "斧头","耐久·钢斧",0,0,0,1,false,70,230 };
                make(thi, num, makething);
            }
            else if (t == "耐久·钢镐")
            {
                string thi[100] = { "钢镐","钢" };
                int num[100] = { 1,100 };
                thing makething = { "镐","耐久·钢镐",0,0,0,1,false,70,230 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "锋利·耐久·钢斧")
            {
                string thi[100] = { "耐久·钢斧","钢合金" };
                int num[100] = { 1,50 };
                thing makething = { "斧头","锋利·耐久·钢斧",0,0,0,1,false,80,230 };
                make(thi, num, makething);
            }
            else if (t == "锋利·耐久·钢镐")
            {
                string thi[100] = { "耐久·钢镐","钢合金" };
                int num[100] = { 1,50 };
                thing makething = { "镐","锋利·耐久·钢镐",0,0,0,1,false,80,230 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "矿洞")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "矿洞";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "钢合金")
            {
                string thi[100] = { "钢","金" };
                int num[100] = { 5,5 };
                thing makething = { "材料","钢合金",0,0,0,1,false,0,1 };
                make(thi, num, makething);
            }
        }
        else if (a == "查看陷阱")
        {
            cout << "草丛一点动静" << endl;
            Sleep(rand() % 10000 + 1000);
            cout << "好像有东西掉进了陷阱" << endl;
            Sleep(rand() % 10000 + 1000);
            cout << "陷阱满了" << endl;
            Sleep(rand() % 10000 + 1000);
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t你获得了" << ran << "块肉！" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "肉")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "食物","肉",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t你获得了" << ran << "片鳞片！" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "鳞片")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "物品","鳞片",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t你获得了" << ran << "片皮毛！" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "皮毛")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "材料","皮毛",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t你获得了" << ran << "片布料！" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "布料")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "材料","布料",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t你获得了" << ran << "颗牙齿！" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "牙齿")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "材料","牙齿",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t你获得了" << ran << "块垃圾！" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "垃圾")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "材料","垃圾",0,0,0,ran,false };
                        break;
                    }
                }
            }
            _getch();
        }
        else if (a == "矿洞")
        {
            if (nowpickaxe.name == "")
            {
                cout << "你未装备着镐啊..." << endl;
                Sleep(1000);
            }
            else
            {
                int ran = rand() % 7 + 3;
                cout << "砰，矿洞里回响着敲打岩石的声音" << endl;
                Sleep((rand() % 10000 + 10000) / nowpickaxe.sharp);
                cout << "几块碎石掉了下来" << endl;
                Sleep((rand() % 10000 + 10000) / nowpickaxe.sharp);
                cout << "一大块岩石倒在地上" << endl;
                Sleep((rand() % 10000 + 10000) / nowpickaxe.sharp);
                cout << "\t你获得了" << ran << "块岩石！" << endl;
                _getch();
                nowpickaxe.durability -= 1;
                if (nowpickaxe.durability <= 0)
                {
                    cout << "但很不幸，你的镐断了..." << endl;
                    cout << "\t你少了一把镐" << endl;
                    for (int i = 0; i < 1000; i++)
                    {
                        if (bag[i].name == nowpickaxe.name)
                        {
                            bag[i].num--;
                            break;
                        }
                    }
                    nowpickaxe = {};
                    _getch();
                }
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "石头")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "材料","石头",0,0,0,ran,false };
                        break;
                    }
                }
            }
        }
        else if (a == "做熏肉")
        {
            string thi[100] = { "肉","木头" };
            int num[100] = { 5,5 };
            thing makething = { "食物","熏肉",0,0,0,1,false,0,10 };
            make(thi, num, makething);
        }
        else if (a == "制造皮革")
        {
            string thi[100] = { "皮毛","" };
            int num[100] = { 5,0 };
            thing makething = { "材料","皮革",0,0,0,1,false,0,10 };
            make(thi, num, makething);
        }
        else if (a == "添柴")
        {
            for (int i = 0; i < 1000; i++)
            {
                if (bag[i].name == "木头")
                {
                    bag[i].num--;
                }
            }
            cout << "房间暖和...";
        }
        else if (a == "种菜")
        {
            if (nowhoe.name == "")
            {
                cout << "你未装备着锄啊..." << endl;
                Sleep(1000);
            }
            else
            {
                int ran = rand() % 20 + 10;
                cout << "种菜中...    请稍等" << endl;
                Sleep((rand() % 30000 + 30000) / nowhoe.sharp);
                cout << "\t你获得了" << ran << "个野菜！" << endl;
                _getch();
                nowhoe.durability -= 1;
                if (nowhoe.durability <= 0)
                {
                    cout << "但很不幸，你的锄断了..." << endl;
                    cout << "\t你少了一把锄" << endl;
                    for (int i = 0; i < 1000; i++)
                    {
                        if (bag[i].name == nowhoe.name)
                        {
                            bag[i].num--;
                            break;
                        }
                    }
                    nowhoe = {};
                    _getch();
                }
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "野菜")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "食物","野菜",0,0,0,ran,false };
                        break;
                    }
                }
            }
        }
        else if (a == "制造配方")
        {
            system("start https://paste.ubuntu.com/p/sm2MWhTXqh/");
        }
        health = maxhealth;
    }
    return 0;
}


//更新计划：
/*
完成存档部分的制作;+ 


*/
