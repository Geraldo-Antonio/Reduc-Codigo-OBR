tarefa seguelinha{
    se(luz(1)<50)entao{
        se(luz(2)<50) entao{
            escrever(1, "DOIS PRETOS")
            escrevernumero(2, ULTIMO)
            frente(150)
            esperar(250)
            se(cor(1)=="VERDE" ou cor(2)=="VERDE")entao{frente(150) esperar(300)}
            se(ULTIMO == 2)entao{
                zerartemporizador()
                enquanto(temporizador()<1800)farei{
					se(cor(1) != "PRETO" e cor(2) != "PRETO") entao{
						direita(1000)
					} senao{
						interromper()
					}
				}
                parar()
                se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
                    tras(300)
                    esperar(150)
                    zerartemporizador()
                    enquanto(temporizador()<3600)farei{
					se(cor(1) != "PRETO" e cor(2) != "PRETO") entao{
						esquerda(1000)
					} senao{
						interromper()
					}
				}
                    parar()
                    se(temporizador()>3600)entao{
                        direita(1000)
                        esperar(3350)
                    }
                }
            } senao se(ULTIMO == 1)entao{
                zerartemporizador()
                enquanto(temporizador()<1800)farei{
					se(cor(1) != "PRETO" e cor(2) != "PRETO") entao{
						esquerda(1000)
					} senao{
						interromper()
					}
				}
                parar()
                se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
                    tras(300)
                    esperar(150)
                    zerartemporizador()
                    enquanto(temporizador()<3600)farei{
					se(cor(1) != "PRETO" e cor(2) != "PRETO") entao{
						direita(1000)
					} senao{
						interromper()
					}
					}
                    parar()
                    se(temporizador()>3600)entao{
                        esquerda(1000)
                        esperar(3350)
                    }
                }
            }
            zerartemporizador()
        } senao{
            ULTIMO = 2
            direita(1000)
            zerartemporizador()
        }
    } senao{
        se(luz(2)<50)entao{
            ULTIMO = 1
            esquerda(1000)
            zerartemporizador()
        } senao {
            frente(150)
        }
    }
}