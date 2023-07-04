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
## ***IK릭***





---------------------------------------------------------------------------

----------------------------------------------------------------------------
## ***IK***




---------------------------------------------------------------------------

----------------------------------------------------------------------------
## ***함수기능들***

*LockOn*



---------------------------------------------------------------------------
