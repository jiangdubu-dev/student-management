#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

typedef struct {
    char name[50];
    int score;
} Student;

void print_student(Student* s) {
    printf("名前: %s 点数: %d 点\n", s->name, s->score);
}

// ① 全学生をファイルに保存する関数
void save_students(Student* students, int count) {
    FILE* fp = fopen("students.txt", "w");
    if (fp == NULL) {  // ← これを追加！
        printf("ファイルを開けませんでした\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        // ここを実装：1人分を1行で保存
        // ヒント: fprintf(fp, "%s %d\n", ???, ???);
      
        fprintf(fp,"%s %d\n",students[i].name, students[i].score);
    }
    fclose(fp);
    printf("保存しました！\n");
}

// ② ファイルから学生を読み込む関数
int load_students(Student* students) {
    FILE* fp = fopen("students.txt", "r");
    if (fp == NULL) return 0;  // ファイルがなければ0人

    int count = 0;
    // ここを実装：EOF（ファイルの終わり）まで読み込む
    // ヒント: while(fscanf(fp, "%s %d", ???, ???) == 2
    while (fscanf(fp, "%s %d", students[count].name, &students[count].score) == 2) {
        count++;
    }

    fclose(fp);
    return count;
}

int main() {
    Student students[5];
    int count = load_students(students);  // 起動時に読み込む
    int choice;

    while (1) {
        printf("\n=== 学生管理システム ===\n");
        printf("1: 学生を登録\n");
        printf("2: 一覧を表示\n");
        printf("3: 保存して終了\n");
        printf("選択してください: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("名前を入力: ");
            scanf("%s", students[count].name);
            printf("点数を入力: ");
            scanf("%d", &students[count].score);
            count++;
            printf("登録しました！\n");

        }
        else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                print_student(&students[i]);
            }

        }
        else if (choice == 3) {
            save_students(students, count);  // 保存して終了
            break;
        }
    }
    return 0;
}