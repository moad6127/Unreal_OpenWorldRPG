# Simple OpenWorld RPG

언리얼 엔진 5를 사용해서 간단한 RPG형 게임을 오픈월드로 만들기


![ScreenShot00001](https://github.com/moad6127/Unreal_MultiPlayShooter/assets/101626318/a9ef161a-4a62-4b76-9962-cb4db7ee02ca)


# *언리얼 엔진5로 오픈월드 맵 만들기*

![OpenWorld_LandScapeMode](https://github.com/moad6127/Unreal_MultiPlayShooter/assets/101626318/584b3957-dc5b-4f75-b45c-a53c7d1df266)
> 랜드스케이프 모드를 사용해서 오픈월드맵을 만들기, 모드의 기능들을 사용해 맵의 높낮이와 여러가지 모양들을 만들어낼수 있다.


![QuixelBredge](https://github.com/moad6127/Unreal_MultiPlayShooter/assets/101626318/e3950726-8b74-41ce-b0c6-c90e02824054)
![OpenWorld_FoliageMode](https://github.com/moad6127/Unreal_MultiPlayShooter/assets/101626318/2b8e89c5-9902-4c17-aa4f-d80ccd1e8f80)
>에픽게임즈의 퀵셀브릿지를 사용해서 맵에 추가할 여러가지 에셋들(풀,나무)등을 다운받고 폴리지모드를 사용해서 원하는 분포와 밀도로 맵에 에셋들을 채울수 있다.




# *캐릭터*

![ScreenShot00002](https://github.com/moad6127/Unreal_MultiPlayShooter/assets/101626318/0190bbbe-ef6f-47a8-ba6c-cabcb8c67bfb)


- [헤더파일 주소](https://github.com/moad6127/Unreal_OpenWorldRPG/blob/master/Source/Slash/Public/Character/SlashCharacter.h)
- [CPP파일 주소](https://github.com/moad6127/Unreal_OpenWorldRPG/blob/master/Source/Slash/Private/Character/SlashCharacter.cpp)

> 사용자가 컨트롤 하는 캐릭터로 기본적인 움직임과 공격 회피등의 기능이 있으며, 캐릭터의 입력기능을 언리얼엔진에서 만든 EnhancedInput의 기능을 사용해서 움직임을 제어하도록 만들었으며 Inverse Kinematic을 적용해서 자연스러운 움직임을 구현하였다.

## **주요 기능들**
----------------------------------------------------------------------------
## ***Enhanced Input***

[언리얼 엔진 문서](https://docs.unrealengine.com/5.0/ko/enhanced-input-in-unreal-engine/)

언리얼 엔진5에서 업데이트되 기능으로트리거와 모디파이어를 사용해 우선순위등을 정할수 있어 엔진4에서는  코딩으로 작업해야 했던 부분들을 코드 없이 작업이 가능해질수도 있어졌다.

![Enhanced_Input_Actions](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/05c5b9b3-6e1b-456a-ac0e-0edd840dc255)
> 엔진으로 InputAction을 만들고 기능에 필요한 값타입을 정한다.
> 값타입에는 bool타입, float타입, vector2D타입, vector타입이 있으며 필요에따라 변경할수 있다.

![mappingContext](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/241dd8f0-fd55-4c82-98c1-a39e60664405)
>입력매핑컨텍스트에 Action들을 설정하고 매핑할 키를 선택해서 입력을 받게 만들수 있다.

![EnhancedInput_ActionsAndFunc](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/c4652e8d-c66c-41ee-89cc-8cf235c53a74)
>엔진에서 만들어진 InputAction과 매핑컨텍스트를 캐릭터클래스로 받기위해 변수를 선언한다.

![Enhanced_Input_CharacterBlueprint](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/bcec9609-c0c5-4938-82ae-6d5faa90bc78)
> 캐릭터 클래스에서 선언된 변수들에 만들어진 Input과 매핑컨텍스트를 캐릭터 블루프린트로 설정한다.

![Enhanced_Input_Cpp_BeginPlay](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/7d5c39ba-1083-4104-b3aa-819e7fba2324)
> 캐릭터 클래스의 변수로 선언된 매핑컨텍스트를 세팅하기위해 BeginPlay에서 다음과 같은 코드를 사용한다.
>
![EnhancedInput_SetupPlayerInputConponent](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/1523bb9a-0886-4925-8de4-c4a9a432cf85)
>엔진4에서 사용하는것과 비슷하게 SetupPlayerInputComponent함수에서 각각에 필요한 함수로 Bind하여 기능을 사용하도록 만든다.


![Enhanced_Input_Functions](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/767612b3-6048-4b6f-96d0-00b397a747d2)
> 사용자의 입력이 들어오면 Input의 변수타입에 맞는 Value를 Value.Get으로 받아와서 입력값을 사용해 함수들을 구현한다.




---------------------------------------------------------------------------


----------------------------------------------------------------------------
## ***IK릭 리타겟팅***
[언리얼 엔진 문서](https://docs.unrealengine.com/5.2/ko/ik-rig-animation-retargeting-in-unreal-engine/)

![IK_Rig_Retargeting](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/621b5c8f-bd53-406c-9936-acde4b077f67)

언리얼 엔진5 기능중 하나로 스켈메탈 메쉬가 다른 캐릭터의 애니메이션을 캐릭터 애니메이션으로 생성시켜 주는 기능으로 비율이 다르더라도 사용해 자연스러운 애니메이션을 얻을수 있다.

![IK_RIg_base](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/64b3a0e9-e5c9-425e-aef2-c935a54a19b1)
>캐릭터의 스켈레탈 메쉬의 IK_Rig




---------------------------------------------------------------------------

----------------------------------------------------------------------------
## ***Inverse Kinematic***

![ScreenShot00005](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/fcb723e1-bdcb-4c07-ad7f-ca5ddd068cf0)

언리얼엔진 기능중 하나인 컨트롤 릭기능을 이용해 Inverse Kinematic기능을 만들고 사용한다.
기본적으로 캐릭터의 발아래에 SphereTrace를 사용해서 이동할 위치를 구한다음 IK_Bone의 위치를 이동시킨다.

![FookIK_Init](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/c90787b7-cafd-4ec4-979c-1593d90b5bc3)
> 캐릭터의 스켈레탈 메쉬의 가상화된 Bone의 위치를 실제 Bone위치로 변경시켜 두Bone을 동기화 시킨다.

![FookIK_FootTrace](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/7168a95b-dd2c-4027-a58f-430c6f7e8e09)
> 컨트롤 릭에서 사용할 FootTrace기능을 함수로 구현한다. Input된 Bone의 위치를 사용해 SphereTrace를 해 결과값을 리턴하도록 만들었다.

![FookIK_SphereTrace](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/26213d8d-59ef-48c1-b85d-da76a1c9268c)
> 만든 함수를 사용해 가상화된 Bone에서 Trace를 해 얻은 결과값들을 따로 변수로 만들어 저장한다.

![FookIK_Interpolate](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/83de0f27-824a-4699-bc08-91c5c8dbf3d5)
>얻은 결과값들을 보간해서 Bone들이 이동할 위치를 설정한다.

![FookIK_LowerBoneCheck](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/efa7a875-4609-4967-b9bb-c6ad3869cb78)
> 결과값중 더 작은값을 정한후 골반뼈의 위치를 잡는다.

![FookIK_MoveVirtualBone](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/8e73a9e6-c8b5-405b-ab89-ca3614c40bb4)
> 얻은 결과값을 토대로 실제 Bone의 위치를 변경시킨다.

![FookIK_MoveBone](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/21ffccf4-a0ec-414b-8de2-3a06f2ec92b1)
> FullBodyIK를 사용해서 이동한 위치에 따라서 모든 몸의 Bone이 자연스럽게 이동하도록 만든다.


---------------------------------------------------------------------------

----------------------------------------------------------------------------
## ***LockOn***


![ScreenShot00004](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/be821015-5205-4bf6-94d3-b5ab941590a7)
주위에 여러개체의 Enemy 가 있을경우 LockOn을 사용해 하나의 개체에 집중할수 있게 만들었다.


![LockOn](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/edd85046-c0b4-40d2-8b2a-123aa2c59051)
> LockOn에 필요한 변수들인 LockOnSphere와 범위내의 Enemy클래스를 알기위해 TArray형식으로 변수를 선언하고, Overlap함수를 오버라이드 한다.

![LockOn_SphereOvelapFunc](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/14c80049-b09a-4416-8347-7da4191e107c)
> 범위내에 Enemy가 들어올경우 만든 TArray변수에 Enemy를 Unique하게 추가하고 범위 밖으로 나갈경우 제거한다, 이때 만약 LockOn된 Enemy일경우 LockOn된 Enemy도 배열에서 지운다.

![LockOnFunc](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/ce33ed23-a85b-46d4-974b-d06b00113a73)
> LockOn버튼을 눌렀을경우 현재 배열내에서 가장 가까운 Enemy를 LockOn하기위해 반복문을 사용해 가장 가까운 Enemy를 찾고 CombatTarget으로 만든다.

![LockOn_Rotation](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/f1517c2b-7761-49ee-8cf8-9a111c683922)
> 만약 LockOn된 CombatTarget이 존재할경우 공격할때 함수를 호출해서 Enemy방향으로 캐릭터를 회전시킨다.


---------------------------------------------------------------------------

---------------------------------------------------------------------------

## ***InventorySystem***

![Character_inventory](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/cf12d891-00b9-4196-bfec-e6a24e44fb76)


- [헤더파일 주소](https://github.com/moad6127/Unreal_OpenWorldRPG/blob/master/Source/Slash/Public/Component/InventoryComponent.h)
- [CPP파일 주소](https://github.com/moad6127/Unreal_OpenWorldRPG/blob/master/Source/Slash/Private/Component/InventoryComponent.cpp)
- 

---------------------------------------------------------------------------

# *Enemy*

![Enemys](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/31e88e42-97ac-4fd9-8be5-af137171b01f)


- [헤더파일 주소](https://github.com/moad6127/Unreal_OpenWorldRPG/blob/master/Source/Slash/Public/Enemy/Enemy.h)
- [CPP파일 주소](https://github.com/moad6127/Unreal_OpenWorldRPG/blob/master/Source/Slash/Private/Enemy/Enemy.cpp)

게임에서 등장하는 Enemy들로 기본적으로 정해진곳을 순찰하며, 플레이어를 발견하면 PawnSeen기능을 통해 플레이어를 추적하고 일정거리 이상오면 공격한다,
이때 공격에서 MotionWarping을 사용해 공격애니메이션중에도 따라가서 공격하도록 만들었다.
Enemy가 죽을경우 Soul을 Spawn하는데 캐릭터가 수집할수 있다.


---------------------------------------------------------------------------
## ***Patrol***

![Enemy_Patrol](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/50bf8a9b-a6b8-4dbf-a790-ce5a7022515b)

Enemy는 기본적으로 계속 순찰을 하며, 순찰할곳을 추가적으로 넣을수 있다.

![Enemy_PatrolVal](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/f3f0a237-94be-4311-87a1-b2d5f78d6bb6)
> Patrol에 필요한 변수들로 처음에 갈곳을 정한후 배열에 추가적으로 순찰할곳을 넣으면 반복적으로 순찰한다.
>
![Enemy_Init](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/1a364a50-181a-41ec-9d38-2e23413751ff)
> Enemy의 BeginPlay에서 호출되는 함수로 이동에 필요한 AIController를 저장하고 기본 순찰지역으로 이동하도록 MoveTo함수를 호출한다.

![Enemy_MoveToTarget](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/5affe652-f27c-4d3b-bf70-00b0af080a1e)
> MoveTo함수에서 이동할 액터와 어느정도범위까지 이동할지 정한후 AIController의 함수를 호출해서 이동한다.
>
![EnemyTIck](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/d5fb124c-5d91-4be3-bb25-961934c15473)
![Enemy_checkTarget](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/a0ff6b1a-6ce4-420b-be1f-acd8f842fa46)
> Tick함수에서 현재 Enemy의 상태를 체크하면서 PatrolTarget이 범위에 들어오면 다시 새로운 Target을 정하고 일정한 시간이 지난후 이동시키도록 만들었다.

![Enemy_ChooseTarget](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/5da21cd4-bcb9-462a-a6e6-71f27805155e)
> Target이 일정범위에 들어오면 새로운 타겟을 정하기위해 호출되는 함수로, 변수로 선언된 PatrolTargets를 반복문으로 돌면서 현재 Target인지 체크한후에 만약 지금 Target과 같으면 제외시키면서 새로운 배열에 추가한다, 이후 랜덤하게 하나의 순찰지역을 선택해서 타겟으로 잡는다.
> 
![Enemy_TimerFinish](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/27c6f4ca-6fa7-4319-9c53-b461baae4bf6)
> 타이머가 끝나면 호출되는 함수로 MoveTo함수를 호출해서 새로운 타겟으로 이동한다.

---------------------------------------------------------------------------

---------------------------------------------------------------------------
## ***Pawn Seen***

![Enemy_PawnSeen (2)](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/df91995d-4b06-46b6-898d-cc0a279d3922)

Enemy 클래스에 PawnSensing컴포넌트를 추가해서 Enemy의 정해진 시야에 Actor가 들어오면 반응 하도록 만들수 있는 컴포넌트이다.
시야뿐 아니라 발소리등으로 반응하도록 만들수도 있다.

![Enemy_Value](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/6583f92d-086a-459e-893e-ed7c4e328d5d)
> 컴포넌트를 사용하기위해 Enemy클래스 헤더파일에 변수를 선언하고 사용할 함수도 같이 선언한다.

![Enemy_PawnSensing](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/6e5bcda6-5e05-43fc-b031-887cfd6741b4)
>컴포넌트를 생성자에서 만든후 필요한 변수들을 초기화 해준다.

![Enemy_BeginPlay](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/71479908-4a09-4f6e-aee0-710497899c29)
> Enemy가 시야에 따라서 반응할수 있도록 BeginPlay 에서 델리게이트를 선언해준다.

![Enemy_PawnSeen](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/314b5be2-d913-4afb-976b-279b6afbc520)
> PawnSeen함수가 호출되면 순찰을 멈춘후, Enemy가 본 캐릭터를 추적하기 시작한다.

![Enemy_ChaseTarget](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/ae6b4c02-4691-48b3-8d8a-18e2a28e4d8e)
> PawnSeen으로 본 액터를 향해 Enemy가 이동한다.


![Enemy_CheckCombatTarget](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/1221fe9f-3224-4c8b-a810-4ddf4a0268dd)
> Tick함수에서 Enemy의 상태가 Chase상태일경우 CheckCombatTarget함수를 호출하게 된다.
> 이때 Enemy와 캐릭터의 거리가 일정부분 멀어지게 되면 다시 순찰을 하도록하며, 공격 범위에 들어올경우 공격하도록 만들었다.

![ScreenShot00004](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/cb7ed11b-c3d2-487f-8516-901fbd6cfef1)

---------------------------------------------------------------------------
# *Item*


------------------------------------------------------------------------------------------------

## ***BreakableActor***

![BreakableActor](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/f5ac9c60-5501-4591-a19d-c93c28b28366)

- [헤더파일 주소](https://github.com/moad6127/Unreal_OpenWorldRPG/blob/master/Source/Slash/Public/Breakable/BreakableActor.h)
- [CPP파일 주소](https://github.com/moad6127/Unreal_OpenWorldRPG/blob/master/Source/Slash/Private/Breakable/BreakableActor.cpp)

Weapon에 FieldsSystem을 추가해서 Weapon이 BreakableActor에 Overlap 되었을때 프텍탈 시스템을 활용해 BreakableActor가 부서지도록 만들기


![Weapon_OnBoxOverlap](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/c645718c-7585-47de-b79c-4f4682e974e4)
> Weapon에 Actor가 Overlap되면 호출되는 함수 CreateFields에 BoxHitResult를 넘겨줘서 어느위치에 Overlap되었는지 알려준다.


![Weapon_CreateFields](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/15c3c6c4-7dc0-471e-905c-7e9e6f109288)
>  블루프린트에서 Overlap함수에서 넘어온 Result값을 사용해서 Fields의 Vector등을 설정후 생성시킨다.


![BreakableActor_ChaosBreakEvent](https://github.com/moad6127/Unreal_OpenWorldRPG/assets/101626318/f65d42cb-6ed5-4d84-91ca-9300fac0feea)
> Field로 힘이 들어올경우 액터가 Break되면서 호출되는 함수로 Treasure를 리스폰 시킨후 3초뒤에 사라지도록 만들었다.



-----------------------------------------------------------------------------------------------
