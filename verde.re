se(cor(1) == "VERDE" ou cor(2) == "VERDE") entao {
    parar()
    frente(100)
    esperar(30)
    zerartemporizador()
    enquanto(temporizador() < 100) farei{
        se(cor(1) == "VERDE" e cor(2) == "VERDE") entao{
            interromper()
        } senao{
            esquerda(1000)
        }			
    }
    zerartemporizador()
    enquanto(temporizador() < 100) farei{
        se(cor(1) == "VERDE" e cor(2) == "VERDE") entao{
            zerartemporizador()
            interromper()
        } senao{
            direita(1000)
        }			
    }
    zerartemporizador()
}
se(cor(1) == "VERDE" e cor(2) == "VERDE") entao {
    parar()
    rotacionar(1000,180)
}senao se(cor(1)=="VERDE" e cor(2) != "VERDE")entao{
    parar()
    escrever(1, "VERDE PARA A DIREITA")
    enquanto(cor(1)=="VERDE")farei{
        se(cor(2)=="VERDE")entao{V2 = verdadeiro}
        frente(150)
    }
    parar()
    se(V2 == falso)entao{
        frente(150)
        esperar(300)
        direita(1000)
        esperar(600)
        enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{direita(1000)}
        parar()
    } senao {
        frente(150)
        esperar(300)
        rotacionar(1000, 90)
        enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{direita(1000)}
        parar()
    }
    V2 = falso
} senao se(cor(2)=="VERDE")entao{
    parar()
    escrever(1, "VERDE PARA A ESQUERDA")
    enquanto(cor(2)=="VERDE")farei{
        se(cor(1)=="VERDE")entao{V2 = verdadeiro}
        frente(150)
    }
    parar()
    se(V2 == falso)entao{
        frente(150)
        esperar(300)
        esquerda(1000)
        esperar(600)
        enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{esquerda(1000)}
        parar()
    } senao {
        frente(150)
        esperar(300)
        rotacionar(1000, 90)
        enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{direita(1000)}
        parar()
    }
    V2 = falso
} senao {
    seguelinha()
}