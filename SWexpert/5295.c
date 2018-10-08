/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf("%d", &a);                      // int 변수 1개 입력받는 예제
// scanf("%f %f", &b, &c);               // float 변수 2개 입력받는 예제 
// scanf("%lf %lf %lf", &d, &e, &f);     // double 변수 3개 입력받는 예제
// scanf("%c", &g);                      // char 변수 1개 입력받는 예제
// scanf("%s", &var);                    // 문자열 1개 입력받는 예제
// scanf("%lld", &AB);                   // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int 변수 1개 출력하는 예제
// printf("%f %f", b, c);                // float 변수 2개 출력하는 예제
// printf("%lf %lf %lf", d, e, f);       // double 변수 3개 출력하는 예제
// printf("%c", g);                      // char 변수 1개 출력하는 예제
// printf("%s", var);                    // 문자열 1개 출력하는 예제
// printf("%lld", AB);                   // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
int main(void)
{
	int test_case;
	int T, N;
    int deleteColumn;
    int i, j, k;
    int a,b,c;
    int rowCount;
	setbuf(stdout, NULL);
	scanf("%d", &T);
    int arr[3][100000];
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//////////2///////////////////////////////////////////////////////////////////////////////////
		/*
		이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		*/
    deleteColumn =0;
        scanf("%d", &N);
        for(rowCount =0; rowCount<3; i++)
        {
            for(i =0 ; i<N;i++)
            {
                scanf("%d", arr[rowCount][i]);
            }
        }
        //input Complete
        printf("#%d %d\n", test_case, deleteColumn);
        
		/////////////////////////////////////////////////////////////////////////////////////////////

	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}