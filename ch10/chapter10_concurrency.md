* [명령어 반복 실행하기 - `;`, `&`, `&&`](https://www.opentutorials.org/module/2538/15818)  
	> `;`는 성공여부 상관없이 다음 명령어 실행  
	> `&&`는 성공해야 다음 명령어 실행  
	> `&` background에서 명령어 실행


* [시간마다 명령어 반복](https://m.blog.naver.com/PostView.nhn?blogId=jinart32&logNo=60011749426&proxyReferer=https%3A%2F%2Fwww.google.com%2F)
	```bash
	$ while true; do 명령어; sleep 1; done;
	```
* [특정 횟수 명령어 반복](https://kr.minibrary.com/349/)  
	이건 되는지 모르겠다
	```bash
	$ for i in `seq COUNT`; do COMMAND; done
	```