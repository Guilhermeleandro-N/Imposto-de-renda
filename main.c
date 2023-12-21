#include <stdio.h>
float deducaodepen(int ndependente);
float deinss(float rendimentos);
float baseproimposto(float rendimentos,float inss,float dedependente);
float impostorenda(float baseimp);
int main()
{
    float rendimentos,inss,impostototal,dedependente,baseimp;
    int ndependente;
    printf("Calculadora de imposto de renda\nRendimentos tributaveis:\n");
    scanf("%f",&rendimentos);
    printf("Dependente(quantidade):\n");
    scanf("%d", &ndependente);
    dedependente=deducaodepen(ndependente);
    inss=deinss(rendimentos);
    baseimp=baseproimposto(rendimentos,inss,dedependente);
    impostototal=impostorenda(baseimp);
    printf("Imposto total:%.2f\nImposto percentual total:%.2f%%\n", impostototal,(impostototal/baseimp)*100);
    return 0;
}

float deducaodepen(int ndependente){
    float dedependente;
    dedependente=ndependente*189.59;
    return dedependente;
}

float deinss(float rendimentos){
    float inss;
    if(rendimentos<=1320){
        inss=rendimentos*0.075;
    }else if(rendimentos>1320 && rendimentos<=2571.29){
        inss=rendimentos*0.09;
    }else if(rendimentos>2571.29 && rendimentos<=3856.94){
        inss=rendimentos*0.12;
    }else if(rendimentos>3856.95 && rendimentos<7507.49){
        inss=rendimentos*0.14;
    }else if(rendimentos>=7507.49){
        inss=7507.49*0.14;
    }
    return inss;
}

float baseproimposto(float rendimentos,float inss, float dedependente){
    float baseimp;
    baseimp=rendimentos-inss-dedependente;
    return baseimp;
}

float impostorenda(float baseimp){
    float a,impostototal=0;
        printf("Quantidade de imposto bruto por faixa:\n0%%= Isento\n");
        if(baseimp>2826.65){
            impostototal+=142.80;
            a=impostototal;
            printf("7,5%%=%.2f\n",impostototal);
        }else if(baseimp>2112 && baseimp<=2826.65){
        impostototal+=baseimp-2112;
        printf("7,5%%=%.2f.2\n",impostototal);
    }
    if(baseimp>3751.05){
        impostototal+=354.80;
        printf("15%%=%.2f\n",impostototal-a);
        a=impostototal;
    }else if(baseimp>2826.65 && baseimp<=3751.05){
        impostototal+=(baseimp-2826.65)*0.15;
        printf("15%%=%.2f\n",impostototal-a);
        a=impostototal;
    }
    if(baseimp>4664.68){
        impostototal+=636.13;
        printf("25%%=%.2f\n",impostototal-a);
        a=impostototal;
    }else if(baseimp>3751.05 && baseimp<=4664.68){
        impostototal+=(baseimp-4664.68)*0.225;
        printf("25%%=%.2f\n",impostototal-a);
        a=impostototal;
    }
    if(baseimp>4664.68){
        impostototal+=(baseimp-4664.68)*0.275;
         printf("27.5%%=%.2f\n",impostototal-a);
    }
    return impostototal;
}
