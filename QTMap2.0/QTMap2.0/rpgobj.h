#ifndef RPGOBJ_H
#define RPGOBJ_H
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>
using namespace std;
class RPGObj
{
public:
    RPGObj(){}

    void initObj(string type);
    void show(QPainter * painter);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}

    bool canCover() const{return this->_coverable;}
    bool canTalk() const{return this->_talkable;}
    bool canEat() const{return this->_eatable;}
    bool canDie() const{return this->_dieable;}
    bool canDelete() const{return this->_deleteable;}
    bool canPass() const{return this->_passable;}


    string getObjType() const{return this->_icon.getTypeName();}//返回类名

protected:
    //所有坐标，单位均为游戏中的格

    QImage _pic;
    int _pos_x, _pos_y;//该物体在游戏中当前位置（左上角坐标）
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息
    bool _coverable;
    bool _eatable;
    bool _dieable;
    bool _talkable;
    bool _deleteable;
    bool _passable;
};

#endif // RPGOBJ_H
