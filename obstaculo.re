se (ultra(1) < 25) entao{
		zerartemporizador()
		se(cor(5)=="BRANCO" e luz(5)>45) entao {
			frente(100)
			esperar(100)
			parar()
			zerartemporizador()
		} senao{
			enquanto(ultra(1)<50)farei{esquerda(1000)}
			parar()
			rotacionar(1000, negativo(20))

            zerartemporizador()
            enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO" e temporizador()<500)farei{frente(300)}
            parar()
            se(cor(1)=="PRETO" ou cor(2)=="PRETO")entao{
                escrever(1, "OBSTACULO PARA ESQUERDA")
                frente(300)
                esperar(300)
                rotacionar(1000, negativo(45))
                zerartemporizador()
                enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
                parar()
            } senao {
                zerartemporizador()
                enquanto(cor(2)=="BRANCO" e (ultra(2)<50) e ultra(1)>20 e ultra(2)>25)farei{frente(100)}
                parar()
                rotacionar(1000, 45)
                frente(300)
                esperar(400)
                enquanto(ultra(2)<50)farei{frente(300)}
                parar()
                rotacionar(1000, 55)
                zerartemporizador()
                enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO" e temporizador()<300)farei{frente(300)}
                parar()
                se(cor(1)=="PRETO" ou cor(2)=="PRETO")entao{
                    escrever(1, "OBSTACULO NORMAL")
                    frente(300)
                    esperar(350)
                    rotacionar(1000, negativo(55))
                    zerartemporizador()
                    enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
                    parar()
                } senao {
                    zerartemporizador()
                    enquanto(cor(2)=="BRANCO" e (ultra(2)<50) e ultra(1)>20 e ultra(2)>25)farei{frente(100)}
                    parar()
                    rotacionar(1000, 45)
                    frente(300)
                    esperar(300)
                    enquanto(ultra(2)<50)farei{frente(300)}
                    parar()
                    rotacionar(1000, 55)
                    zerartemporizador()
                    enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO" e temporizador()<300)farei{frente(100)}
                    parar()
                    escrever(1, "OBSTACULO PARA DIREITA")
                    frente(300)
                    esperar(300)
                    rotacionar(1000, negativo(60))
                    zerartemporizador()
                    enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
                    parar()
                }
            }
	    }
	zerartemporizador()
	} senao{
		verde()
 	}