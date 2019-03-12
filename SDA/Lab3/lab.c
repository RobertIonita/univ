

int main() {
    /// 1 enumerare ///

    typedef enum {
        red,
        yellow,
        blue,
        green
    } color;
    
    color v;

    scanf("%d", &v);
    printf("%d", v);

    switch (v) {
        case red:
            printf("red");
            break;
        case yellow:
            printf("yellow");
            break;
        case blue:
            printf("blue");
            break;
        case green:
            printf("green");
            break;
        default:
            break;
    }
    /// 2 articol ///

    typedef struct stud {
        char name[20];
        char surname[20];
        float height;
        
    } student;

    student s[20];


    /// 3 articol cu variante ///




    /// propuse ///

    typedef enum {
        medii,
        superioare,
        doctorat
    } studii;

    typedef enum {
        econominc,
        tehnic
    } profil;

    typedef struct {
        float media_bac,
            media_liceu;
    } m;

    typedef union a {
        m inf;
        float media_liceu;
        float media_liceu;
    } a;



    typedef struct pers {
        char nume[20];
        char prenume[20];
        int zi,
            luna,
            an;
        float salarii;
        a p;
        studii y;
    } pers;


    int citire_F(pers tab[]) {
        FILE * f;
        int i = 0;
        if ((f = fopen("SDA/Lab3/file.txt", "rt")) == NULL) {
            printf("error");
        } else {
            while (!feof(f)) {
                fscanf("%s %s %d %d %d %f %d",
                    tab[i].nume,
                    tab[i].prenume,
                    &tab[i].zi,
                    &tab[i].luna,
                    &tab[i].an,
                    &tab[i].salariu,
                    &tab[i].y);
                
                switch (tab[i].y) {
                    case 0:
                        fscanf(f, "%f %f",
                            &tab[i].p.inf.media_bac,
                            &tab[i].p.inf.media_liceu;
                        );
                        break;
                    case 1:
                        fscanf(f, "%f",
                            &tab[i].p.inf.media_liceu;
                        );
                        break;
                    case 2:
                        fscanf(f, "%f",
                            &tab[i].p.inf.media_liceu;
                        );
                        break;
                    default:
                        break;
                }
            }
        }
    } 

}
