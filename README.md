# Quick Reference "Jellibi = Arduino Nano" 

 [코드크런치 까페(네이버)](https://cafe.naver.com/codecrunch)   

 <TABLE>
 <TR><TD nowrap>
     <a href="https://smartstore.naver.com/robotnmore" target=new>
         <img src="https://dthumb-phinf.pstatic.net/?src=%22http%3A%2F%2Fwww.robotnmore.com%2Fdownload%2Fcodecrunch%2Fcafe_door_20190225_01.jpg%22&type=cafe_wa740">
     </a>    
     <a href="https://www.facebook.com/codecrunch.official/" target=new>
     <img src="https://dthumb-phinf.pstatic.net/?src=%22http%3A%2F%2Fwww.robotnmore.com%2Fdownload%2Fcodecrunch%2Fcafe_door_20190225_02.jpg%22&type=cafe_wa740">
     </a>
     <a href="https://www.instagram.com/codecrunch.official/" target=new>
     <img src="https://dthumb-phinf.pstatic.net/?src=%22http%3A%2F%2Fwww.robotnmore.com%2Fdownload%2Fcodecrunch%2Fcafe_door_20190225_03.jpg%22&type=cafe_wa740">
     </a>
     </TD></TR>
 </TABLE>


`JellibiSample` 저장소(https://github.com/signaled/JellibiSample) 에서는 아두이노나노 호환보드인 젤리비보드를 주행로봇, 그리퍼 등을 제어하는 샘플코드를 살펴볼 수 있습니다.  

이 문서에서는 아두이노 플랫폼의 간단한 소개와 아두이로 플랫폼을 통해서 로봇젤리비를 움직이거나 그리퍼를 조작하는데 필요한 기초적인 제어신호와 아두이노에서 제어신호를 만들어 내는 방법에 대해 설명합니다. 

## 아두이노 Quick Setup

아두이노의 역사나 원리등의 배경지식은 [여기서(wikipedia)](https://ko.wikipedia.org/wiki/%EC%95%84%EB%91%90%EC%9D%B4%EB%85%B8) 살펴 볼 수 있습니다. 

- 아두이노 설치 
  - 윈도우즈의 마이크로소프트 스토어, 우분투의 소프트웨어 센터에서 아두이노를 설치 할 수 있습니다.
  - 또한 아두이노의 공식 홈페이지(https://www.arduino.com)에서도 아두이노 툴을 다운로드 받아 설치 할 수 있습니다.  
- 아두이노 실행 및 젤리비 보드 연결 
  - 아두이노와 젤리비보드의 연결은 시리얼포트를 통해 연결됩니다. 
  - 젤리비보드의 마이크로 USB 단자와 PC 의 USB 단자를 연결하면    
    윈도우는 젤리비보드와 연결할 수 있는 시리얼 포트를 만들어 준비합니다.    
    -  "CH340" USB to Serial 칩셋  드라이버를 PC 에 설치 할 필요가 있습니다. 
  - 시리얼포트의 이름(번호) 는 윈도우의 장치 관리자에서 확인할 수 있습니다. (ex. COM1) 
    

