#ifndef SOD_PLAY_H
#define SOD_PLAY_H

#include "SOD_Runtime.h"

#define SOD_WORLD_WIDTH 1200 //������
#define SOD_WORLD_HEIGHT 900 //����߶�
#define SOD_WORLD_UPDATE_ATOM 10 //������������

#define SOD_USER_BULLET_DAMAGE 5 //���Ƿɴ��ڵ��˺�
#define SOD_ALIEN_BULLET_DAMAGE 5 //���Ƿɴ��ڵ��˺�
#define SOD_STONE_IMPACT_DAMAGE 15//ʯͷ��ײ�˺�
#define SOD_GHOST_IMPACT_DAMAGE 15//�����ײ�˺�
#define SOD_ALIEN_IMPACT_DAMAGE 5//���Ƿɴ���ײ�˺�

#define SOD_SHIP_DEFAULT_FIRE_DURATION 350//��ʼ��������
#define SOD_MIN_FIRE_DURATION 100 //��С��������
#define SOD_STONE_GEN_SPACE 300 //���ɼ��,�����޸�
#define SOD_STONE_DEFALUE_MIN_ROTATION_SPEED 10 //ʯͷ��С��ת�ٶ�
#define SOD_STONE_DEFALUE_MAX_ROTATION_SPEED 360 //ʯͷ�����ת�ٶ�
#define SOD_GHOST_SEARCH_DISTANCE 200 //��������뾶
#define SOD_ALIEN_SEARCH_DISTANCE 280 //�����������뾶
#define SOD_USER_SEARCH_DISTANCE 400 //user�����뾶
#define SOD_GHOST_SPEED 100//����ٶ�
#define SOD_ALIEN_SPEED 150//�������ٶ�
#define SOD_STAR_SPEED  50 //�����ٶ�
#define SOD_SHIP_FORCE_MAX_DISTANCE 200//�ɴ���������
#define SOD_SHIP_DEFAULT_MAX_LIFE  100 //��ʼ�������
#define SOD_SHIP_DEFAULT_MAX_ATOM  100 //��ʼ����ӵ�����
#define SOD_SHIP_DEFAULT_MAX_FORCE 100 //��ʼ�������
#define SOD_SHIP_DEFAULT_MAX_UPDATE_FORCE 300//�����������
#define SOD_SHIP_DEFAULT_MAX_SPEED 300 //����ٶ�

#define SOD_STAR_BUFFER_ATOM    20 //���ǲ��䵯ҩ����
#define SOD_STAR_BUFFER_HEALTH  20 //���ǻָ���������
#define SOD_STAR_BUFFER_FORCE   10 //������������
#define SOD_STAR_BUFFER_WEAPON  10 //���������ٶ���������

#define SOD_DROP_PERCENT 60//��Ʒ����
#define SOD_DEFAULT_STONE_GEN_DURATION 1000 //������ʯ����ʱ��
#define SOD_MIN_STONE_GEN_DURATION 500 //��С��ʯ����ʱ��


#define SOD_GHOST_GEN_SCORE  500//��꿪ʼ���ֵķ���
#define SOD_DEFAULT_GHOST_GEN_DURATION 3000 //���ֹ������ʱ��
#define SOD_MIN_GHOST_GEN_DURATION 2000 //��С�������ʱ��

#define SOD_ALIEN_GEN_SCORE  1500//�����˿�ʼ���ֵķ���
#define SOD_DEFAULT_ALIEN_GEN_DURATION 4000 //��������������ʱ��
#define SOD_MIN_ALIEN_GEN_DURATION 2500 //��С����������ʱ��

#define SOD_ALIEN_ATOM_ALIVE_TIME 8000 //�������ڵ�����ʱ��
#define SOD_ALIEN_ATOM_SPEED 80 //�������ڵ�����ٶ�
#define SOD_USER_ATOM_SPEED 180 //�û��ڵ�����ٶ�
#define SOD_DEFAULT_ATOM_SPEED 600 //Ĭ���ӵ��ٶ�
#define SOD_FIRE_PARTICAL_ALIVE_TIME 300 //��������ʱ�� �����޸�
#define SOD_FIRE_SHIP_ATOM_ALIVE_TIME 2000 //�ӵ��������ʱ��

#define SOD_PARTICAL_MP_FIRE 1024*1024 //1M �ڴ�ؿռ���������� �����޸�
#define SOD_PARTICAL_MP_EXPLODE 1024*1024 //1M �ڴ�ؿռ����ը���� �����޸�

#define SOD_USEROBJECT_SPEED 60
#define SOD_USER_ATOM_ALIVE_TIME 8000 //user�ڵ�����ʱ��
//IMPACT
#define SOD_IMPACTTEST_OBJECTTYPE_USER			1
#define SOD_IMPACTTEST_OBJECTTYPE_ENEMY			2
#define SOD_IMPACTTEST_OBJECTTYPE_NEUTRALITY	8

//Layer
#define SOD_ATOM_Z 3
#define SOD_STAR_Z 6
#define SOD_PARTICAL_FIRE_Z 9
#define SOD_STONE_Z 20
#define SOD_GHOST_Z 18
#define SOD_ALIEN_Z 17
#define SOD_SHIP_Z 10
#define SOD_EXPLOSION_Z 6

//EVENTS
#define SOD_OBJECT_EVENT_DAMAGE 0x1001
#define SOD_OBJECT_EVENT_ATOM 0x1002
#define SOD_OBJECT_EVENT_HEALTH 0x1003
#define SOD_OBJECT_EVENT_ADDFORCE 0x1004
#define SOD_OBJECT_EVENT_ADDWEAPON 0x1005
#define SOD_OBJECT_EVENT_SHIELD 0x1006

typedef enum
{
	SOD_OBJECT_TYPE_SHIP,
	SOD_OBJECT_TYPE_SHIP_ATOM,
	SOD_OBJECT_TYPE_PARTICAL,
	SOD_OBJECT_TYPE_STONE,
	SOD_OBJECT_TYPE_GHOST,
	SOD_OBJECT_TYPE_ALIEN,
	SOD_OBJECT_TYPE_USEROBJECT,
	SOD_OBJECT_TYPE_ALIEN_ATOM,
	SOD_OBJECT_TYPE_USER_ATOM,
	SOD_OBJECT_TYPE_STAR,
}SOD_OBJECT_TYPE;

//���������ɴ�����������Ϣ�Ľṹ��
typedef struct
{
	px_int life;//����
	px_texture *shipObject;//�ɴ�����
	px_texture *shieldtex;
	px_point velocity;//��ǰ�ٶ�
	px_point force;//��ǰ����
	px_point direction;//��ǰ����

	px_int atomcount;//��ǰ�ӵ�����
	px_int max_atomcount;//����ӵ�����
	px_int max_life;//�������
	px_float max_force;//����ƶ���
	px_float max_speed;//����ٶ�
	px_bool showHelpLine;//������

	px_dword fire_duration;//�����ӵ����
	px_dword fire_elpased;//�����ϴη����ӵ�����ʱ��
	px_bool shield;
	px_char *Buffer_Text;
	px_dword Buffer_Text_elpased;

	px_point power_main_point,power_assist_L_point,power_assist_R_point;//�������� ����������ê��
	px_point cannon_point1,cannon_point2;//����ê��
}SOD_Play_Object_Ship;


//���������ɴ�����ʱ����ϵͳ,*��Ҫ���ٵ��ڴ���ͷŷ���,���齨���������ڴ��ϵͳ
typedef struct
{
	/*�������*/
	px_dword alive;//���Ӵ���ʱ��
	px_float range;//���ӷ���ʱ��Χ

	PX_Partical_Launcher launcher;
}SOD_Play_Object_ParitcalLauncher;


//���������ɴ�������ӵ�
typedef struct
{
	px_dword alive;//�ӵ�����ʱ��
	px_dword show_impact_region;
	px_texture *tex;
	px_point velocity;//��ǰ�ٶ�
}SOD_Play_Object_ShipFireAtom;

//�����������Ƿɴ�������ӵ�
typedef struct
{
	px_dword alive;//�ӵ�����ʱ��
	px_animation af_animation;
	px_point velocity;//��ǰ�ٶ�
}SOD_Play_Object_AlienFireAtom;


//����������ʯ
typedef struct
{
	px_int life; //��ʯ����
	px_float scale;//��ʯ���Ŵ�С
	px_point velocity;//�ٶ�
	px_float rotation;//��ת�Ƕ�
	px_float rotationSpeed;//��ת�Ƕ�
	px_texture *pTexture;//����
	px_bool show_impact_region;
	px_dword beAttackElpased;//��һ�α�����ʱ��
}SOD_Play_Object_Stone;


//�����������
typedef enum
{
	SOD_PLAY_GHOST_STATUS_NORMAL,
	SOD_PLAY_GHOST_STATUS_ANGRY,
}SOD_PLAY_GHOST_STATUS;

typedef struct
{
	px_int life;
	px_point velocity;//�ٶ�
	px_animation alien_animation;//������
	px_dword beAttackElpased;//��һ�α�����ʱ��
	SOD_PLAY_GHOST_STATUS status;
}SOD_Play_Object_Ghost;


//��������������
typedef enum
{
	SOD_PLAY_ALIEN_STATUS_NORMAL,
	SOD_PLAY_ALIEN_STATUS_ANGRY,
	SOD_PLAY_ALIEN_STATUS_VERYANGRY,
}SOD_PLAY_ALIEN_STATUS;

typedef struct
{
	px_int life;
	px_int atom_count;
	px_dword atom_elpased;
	px_point velocity;//�ٶ�
	px_animation alien_animation;//������
	px_dword beAttackElpased;//��һ�α�����ʱ��
	SOD_PLAY_ALIEN_STATUS status;
}SOD_Play_Object_Alien;



//�û��Խ�
typedef struct
{
	px_int life;
	px_dword atom_elpased;
	px_point velocity;//�ٶ�
	px_animation user_animation;//������
	px_dword beAttackElpased;//��һ�α�����ʱ��
}SOD_Play_Object_UserObject;

//�û��Խ�������
typedef struct
{
	px_float rotation;
	px_float rotationSpeed;
	px_texture *tex;
	px_dword alive;//�ӵ�����ʱ��
	px_point velocity;//��ǰ�ٶ�
}SOD_Play_Object_UserBullet;

//��������
typedef enum
{
	SOD_PLAY_STAR_TYPE_HEAL = 0,
	SOD_PLAY_STAR_TYPE_ATOM,
	SOD_PLAY_STAR_TYPE_FORCE,
	SOD_PLAY_STAR_TYPE_WEAPON,
	SOD_PLAY_STAR_TYPE_SHIELD,
}SOD_PLAY_STAR_TYPE;

typedef struct
{
	SOD_PLAY_STAR_TYPE type;
	PX_TEXTURERENDER_BLEND blend;
	px_point velocity;//�ٶ�
	px_animation star_animation;//������
}SOD_Play_Object_Star;


//�����������ָ��
typedef struct
{
	px_texture tex;
	px_float rotation;
}SOD_Play_Object_Cursor;


//���ڼ�¼IO��������
typedef struct
{
	px_int mouse_x,mouse_y;
	px_char mouse_ldown;
	px_char mouse_rdown;
}SOD_Play_Control;


typedef struct
{
	SOD_Play_Control control;
	px_memorypool fire_mp;//���ڿ�������ϵͳ���ڴ��
	px_memorypool explode_mp;//���ڱ�ը����ϵͳ���ڴ��

	px_int timeProcess;
	px_int showScore;
	px_int bossscore;
	px_int score;
	px_dword stone_genElpased;
	px_dword alien_genElpased;
	px_dword ghost_genElpased;
	px_int fps;
	px_dword gameover_waiting;
	px_dword fps_frame;
	px_dword fps_elpased;
	px_dword gametime;
	px_dword updatetime_reserved;
	SOD_Runtime *runtime;
	PX_World world;
	SOD_Play_Object_Cursor cursor;
	PX_Object *root;
	PX_Object *shipObject;
	PX_Object *ship_powerpartical_main,*ship_powerpartical_l1,*ship_powerpartical_l2;
}SOD_Play;



SOD_Play_Object_AlienFireAtom *SOD_Object_GetAlienFireAtom(PX_Object *pObject);
SOD_Play_Object_Alien *SOD_Object_GetAlien(PX_Object *pObject);
SOD_Play_Object_Ghost *SOD_Object_GetGhost(PX_Object *pObject);
SOD_Play_Object_Stone *SOD_Object_GetStone(PX_Object *pObject);
SOD_Play_Object_ShipFireAtom *SOD_Object_GetShipFireAtom(PX_Object *pObject);
SOD_Play_Object_ParitcalLauncher *SOD_Object_GetParticalLauncher(PX_Object *pObject);
SOD_Play_Object_Ship *SOD_Object_GetShip(PX_Object *pObject);


px_bool SOD_PlayInitialize(SOD_Runtime *runtime,SOD_Play *pPlay);
px_void SOD_PlayRenderUI(SOD_Play *pPlay);
px_void SOD_PlayReset(SOD_Play *pPlay);
px_void SOD_PlayUpdate(SOD_Play *pPlay,px_dword elpased);
px_void SOD_PlayRender(SOD_Play *pPlay,px_dword elpased);
px_void SOD_PlayPostEvent(SOD_Play *pPlay,PX_Object_Event e);

PX_Object* SOD_Object_ParticalLauncherCreate(SOD_Play *play,px_memorypool *mp,PX_ParticalLauncher_InitializeInfo init_info,px_dword alive);

#endif