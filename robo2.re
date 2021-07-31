numero sense1 = 0
numero sense2 = 0
tarefa seguelinha{
    se(luz(1)<40)entao{
        se(luz(2)<40) entao{
            parar()
        } senao{
            direita(1000)
        }
    } senao{
        se(luz(2)<40)entao{
            esquerda(1000)
        } senao {
            frente(120)
        }
    }
}
tarefa curva90{
    se(luz(1)<10)entao{
        frente(300)
        esperar(100)
        enquanto(cor(2)=="BRANCO")farei{direita(1000)}
    } senao se(luz(2)<10) entao{
        frente(300)
        esperar(100)
        enquanto(cor(1)=="BRANCO")farei{esquerda(1000)}
    } senao{
        seguelinha()
    }
}
inicio
velocidadeatuador(150)
levantar(900)
zerartemporizador()

enquanto(verdadeiro)farei{
    curva90()
}
fim