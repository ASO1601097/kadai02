/************************************************/
/*  kadai.c
/*
/*  日付1と日付2の間の日数を計算。
/*
/************************************************/

#include <stdio.h>
#include <cstring>
#include <stdlib.h>

/************************************************/
/*  main
/*
/*  パラメータ : なし
/*  戻り値     : なし 
/*
/*  日付1と日付2を入力し間の日数を表示する。
/************************************************/


int main (void)
{
    int Year1=0,Year2=0,Mon1=0,Mon2=0,Day1=0,Day2=0,Day_cnt=0;		/* 日付1と日付2の年月日格納 */
    int     chk_date,chk_date2					;					/* 月と日をチェック用 */
    char    conv[ 10 ];												/* 日付を文字列にする */
    char    work[ 128 ];											/* 入力された日付を格納*/

    while( 1 ) {
        printf( "\n 日付1( YYYYMMDD  )" );

        work[ 0 ] = '\0';
        scanf( "%s", work );

        if( strlen( work ) != 8 ) {									/* 年月日をきちんと入力するまで繰り返し */
            printf( "\n 入力ミスです" );
            continue;
        }

        if( strspn( work, "1234567890" ) < strlen( work ) ) {
            printf( "\n 数値以外が入力されました" );
            continue;
        }

        conv[0] = work[4];
        conv[1] = work[5];
        conv[2] = '\0';

        chk_date = atoi( conv );
        if( chk_date > 12 || chk_date < 1 ) {
            printf( "\n 日付( 月 )入力エラーです" );
            continue;
        }

        conv[0] = work[6];
        conv[1] = work[7];
        conv[2] = '\0';
        chk_date2 = atoi( conv );
        if( chk_date2 > 31 || chk_date2 < 1 ) {
            printf( "\n 日付( 日 )入力エラーです" );
            continue;
        }

        break;
    }
    conv[0] = work[0];											/* 年の千の位代入 */
    conv[1] = work[1];											/* 年の百の位代入 */
    conv[2] = work[2];											/* 年の十の位代入 */
    conv[3] = work[3];											/* 年の一の位代入 */
    conv[4] = '\0';
    Year1 = atoi(conv);
    Mon1 = chk_date;
    Day1 = chk_date2;
    
        while( 1 ) {
        printf( "\n 日付2( YYYYMMDD  )" );

        work[ 0 ] = '\0';
        scanf( "%s", work );

        if( strlen( work ) != 8 ) {								/* 年月日をきちんと入力するまで繰り返し */
            printf( "\n 入力ミスです" );
            continue;
        }

        if( strspn( work, "1234567890" ) < strlen( work ) ) {
            printf( "\n 数値以外が入力されました" );
            continue;
        }

        conv[0] = work[4];
        conv[1] = work[5];
        conv[2] = '\0';

        chk_date = atoi( conv );
        if( chk_date > 12 || chk_date < 1 ) {
            printf( "\n 日付( 月 )入力エラーです" );
            continue;
        }

        conv[0] = work[6];
        conv[1] = work[7];
        conv[2] = '\0';
        chk_date2 = atoi( conv );
        if( chk_date2 > 31 || chk_date2 < 1 ) {
            printf( "\n 日付( 日 )入力エラーです" );
            continue;
        }

        break;
    }
    conv[0] = work[0];											/* 年の千の位代入 */
    conv[1] = work[1];											/* 年の百の位代入 */
    conv[2] = work[2];											/* 年の十の位代入 */
    conv[3] = work[3];											/* 年の一の位代入 */
    conv[4] = '\0';
    Year2 = atoi(conv);
    Mon2 = chk_date;
    Day2 = chk_date2;

    printf("%d日です。",niti(Year1,Year2,Mon1,Mon2,Day1,Day2,Day_cnt));
}

/************************************************/
/*  niti
/*
/*  パラメータ : Year1,Year2,Mon1,Mon2,Day1,Day2,Day_cnt
/*  戻り値     : int Day_cnt 
/*
/*  日付1と日付2の間の日数をカウントする。
/************************************************/


int niti(Year1,Year2,Mon1,Mon2,Day1,Day2,Day_cnt)
{
	int leap=0;
	while((Year1 != Year2) || (Mon1 != Mon2) || (Day1 != Day2)) {
		if(Mon1 == 2) {
			leap = leap_inv(Year1,leap);								/* うるう年計算 */
			if(leap == 0 && Day1 == 28) {
				Mon1++;
				Day1=1;
				Day_cnt++;
			}
			else if(leap == 1 && Day1==29) {						/* うるう年の月末処理 */
				Mon1++;
				Day1=1;
				Day_cnt++;
			}
			else {
				Day1++;
				Day_cnt++;
			}
		}
		else if(Day1 == 30) {
			if((Mon1 ==4) || (Mon1 == 6) || (Mon1 == 9) || (Mon1 == 11)) {
				Mon1++;
				Day1=1;
				Day_cnt++;
			}
			else {
				Day1++;
				Day_cnt++;
			}
		}
		else if(Day1 == 31) {
			if(Mon1 == 12) {									/* 年末処理 */
				Mon1 = 1;
				Day1 = 1;
				Day_cnt++;
				Year1++;
			}
			else {
				Mon1++;
				Day1 = 1;
				Day_cnt++;
			}
		}
		else {
			Day1++;
			Day_cnt++;
		}
	}

	return Day_cnt;
}


/************************************************/
/*  leap_inv
/*
/*  パラメータ : Year1,leap
/*  戻り値     : int leap
/*
/*  日付1の年がうる年か判定
/************************************************/


int leap_inv(Year1,leap)
{
	if((Year1 % 4 == 0) && (Year1 % 100 != 0) || (Year1 % 400 == 0) ) {
		leap =1;

	}
	else {
		leap = 0;
	}
	return leap ;
}
