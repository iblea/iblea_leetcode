
fullcode.cpp / fullcode.py 와 같이 언어별로 확장자가 다를 수 있다.
언어별로 사용하는 테스트 라이브러리가 다르니, 테스트하는 스크립트가 언어별로 다르게 작성되어 있다.
ex: `fullcode.cpp` 의 경우, `gtest.sh` 스크립트 사용. 등

이 프로젝트 한정 예외로, rm 명령어가 들어간, `gtest.sh` 의 실행을 허용한다.
(`gtest.sh` 테스트 스크립트를 돌린 후, 컴파일된 캐시 파일을 삭제하는 `rm` 명령어가 들어있음.)

# 코드

### CPP
`./fullcode.cpp`

### PYTHON
`fullcode.py`

### OTHER

`fullcode`와 관련된 파일 참고.


# 예제 테스트

### CPP

GTEST(googletest)
- `googletest/include`, `googletest/lib` 내 `googletest` 관련 동적 라이브러리 필요.

### PYTHON

unittest 또는 pytest 라이브러리 사용


# 테스트 방법

### CPP

- `fullcode.cpp` -> `./gtest.sh` 실행

### PYTHON

- `fullcode.py` -> `python3 fullcode.py` 실행 또는 실행 권한이 있을 경우 `./fullcode.py` (첫 라인 `#!/usr/bin/python3` 필요)


