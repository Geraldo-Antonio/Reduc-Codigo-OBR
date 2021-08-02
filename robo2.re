numero sense1 = 0
numero sense2 = 0
numero velocidade = 100
booleano temp = verdadeiro
numero tempCont = 0
numero ULTIMO = 0
numero triangulo = 0
numero recuar = 0
numero graus = 0
tarefa alinhar {
    escrevernumero(2, direcao())
	se(direcao()>230 e direcao()<300)entao{
	    escrever(1, "270")
	    rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=270)farei{esquerda(1000)}
		parar()
	} senao se(direcao()>300 ou direcao()<40)entao{
		escrever(1, "0")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=0)farei{esquerda(1000)}
		parar()
	} senao se(direcao()>40 e direcao()<130)entao{
		escrever(1, "90")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=90)farei{esquerda(1000)}
		parar()
	} senao se(direcao()>130 e direcao()<230)entao{
		escrever(1, "180")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=180)farei{esquerda(1000)}
		parar()
	}
}

tarefa seguelinha{
    se(cor(1)=="PRETO")entao{
        se(cor(2)=="PRETO") entao{
            parar()
            esquerda(1000)
            esperar(150)
            se(cor(2)=="BRANCO")entao{
                frente(300)
                esperar(150)
                zerartemporizador()
                enquanto(cor(1)=="BRANCO" e temporizador()<1500)farei{direita(1000)}
                parar()
                se(cor(1)=="BRANCO")entao{
                    enquanto(cor(2)=="BRANCO")farei{esquerda(1000)}
                    parar()
                    zerartemporizador()
                }
            } senao se(cor(2)=="PRETO")entao{
                frente(300)
                esperar(150)
                zerartemporizador()
                enquanto(cor(1)=="BRANCO" e temporizador()<1500)farei{esquerda(1000)}
                parar()
                se(cor(1)=="BRANCO")entao{
                    enquanto(cor(2)=="BRANCO")farei{direita(1000)}
                    parar()
                    zerartemporizador()
                }
            }
            zerartemporizador()
        } senao{
            direita(1000)
            zerartemporizador()
        }
    } senao{
        se(cor(2)=="PRETO")entao{
            esquerda(1000)
            zerartemporizador()
        } senao {
            frenterotacao(velocidade, 0.1)
        }
    }
}
tarefa curva90{
    se(luz(1)<2)entao{
        escrever(1, "CURVA DE 90 PARA A DIREITA")
        ULTIMO = 1
        frente(300)
        esperar(150)
        se(cor(1)=="VERDE" ou cor(2)=="VERDE")entao{
            enquanto(cor(1)=="VERDE" ou cor(2)=="VERDE")farei{frente(100)}
            parar()
        }
        zerartemporizador()
        enquanto(cor(2)=="BRANCO" e temporizador()<2500)farei{direita(1000)}
        parar()
        se(cor(2)=="BRANCO")entao{
            enquanto(cor(1)=="BRANCO")farei{esquerda(1000)}
            parar()
            zerartemporizador()
        }
        zerartemporizador()
    } senao se(luz(2)<2) entao{
        escrever(1, "CURVA DE 90 PARA A ESQUERDA")
        ULTIMO = 2
        frente(300)
        esperar(150)
        se(cor(1)=="VERDE" ou cor(2)=="VERDE")entao{
            enquanto(cor(1)=="VERDE" ou cor(2)=="VERDE")farei{frente(100)}
            parar()
        }
        zerartemporizador()
        enquanto(cor(1)=="BRANCO" e temporizador()<2500)farei{esquerda(1000)}
        parar()
        se(cor(1)=="BRANCO")entao{
            enquanto(cor(2)=="BRANCO")farei{direita(1000)}
            parar()
            zerartemporizador()
        }
        zerartemporizador()
    } senao{
        seguelinha()
    }
}
tarefa verde{
	se(cor(1)=="VERDE")entao{
		parar()
        escrever(1, "VERDE PARA A DIREITA")
		zerartemporizador()
		enquanto(cor(1)=="BRANCO" e cor(2)=="VERDE")farei{frente(60)}
		parar()
		frente(100)
		esperar(50)
		parar()
		esperar(100)
		se(cor(2)=="VERDE")entao{
            enquanto(cor(2)=="VERDE")farei{esquerda(1000)}
            parar()
            se(cor(2)=="PRETO")entao{
                frente(300)
			    esperar(300)
			    direita(1000)
			    esperar(600)
			    enquanto(cor(2)=="BRANCO")farei{direita(1000)}
			    parar()
            } senao {
			    rotacionar(1000, negativo(90))
			    enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO")farei{esquerda(1000)}
            }
		} senao {
			frente(300)
			esperar(300)
			direita(1000)
			esperar(600)
			zerartemporizador()
			enquanto(cor(2)=="BRANCO" e temporizador()<2500)farei{direita(1000)}
			parar()
			se(cor(2)=="BRANCO")entao{
				tras(300)
				esperar(70)
				enquanto(cor(1)=="BRANCO")farei{esquerda(1000)}
				parar()
			}
		}
		zerartemporizador()
	} senao se(cor(2)=="VERDE")entao{
		parar()
        escrever(1, "VERDE PARA A ESQUERDA")
		zerartemporizador()
		enquanto(cor(2)=="BRANCO" e cor(1)=="VERDE")farei{frente(60)}
		parar()
		frente(100)
		esperar(50)
		parar()
		esperar(100)
		se(cor(1)=="VERDE")entao{
            enquanto(cor(1)=="VERDE")farei{direita(500)}
            parar()
            se(cor(1)=="PRETO")entao{
                frente(300)
			    esperar(300)
			    esquerda(1000)
			    esperar(600)
			    enquanto(cor(1)=="BRANCO")farei{esquerda(1000)}
			    parar()
            } senao {
			    rotacionar(1000, 90)
			    enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO")farei{direita(1000)}
            }
		} senao {
			frente(300)
			esperar(300)
			esquerda(1000)
			esperar(600)
			zerartemporizador()
			enquanto(cor(1)=="BRANCO" e temporizador()<2500)farei{esquerda(1000)}
			parar()
			se(cor(1)=="BRANCO")entao{
				tras(300)
				esperar(70)
				enquanto(cor(2)=="BRANCO")farei{direita(1000)}
				parar()
			}
		}
		zerartemporizador()
	} senao {
		curva90()
	}
}

tarefa obstaculo{
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

			frente(300)
			esperar(400)
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
            enquanto(cor(2)=="BRANCO" e temporizador()<2150)farei{frente(100)}
            parar()
            se(cor(2)!="PRETO" e cor(3)!="PRETO")entao{
                rotacionar(1000, 40)
                enquanto(ultra(2)<50)farei{frente(300)}
                parar()
                rotacionar(1000, 60)
                enquanto(cor(2)=="BRANCO")farei{frente(100)}
                parar()
                frente(300)
                esperar(300)
                rotacionar(1000, negativo(60))
                zerartemporizador()
                enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
                parar()
            } senao{
                frente(300)
                esperar(300)
                rotacionar(1000, negativo(55))
                zerartemporizador()
                enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
                parar()
            }
		
	    }
	zerartemporizador()
	} senao{
		verde()
 	}
}
tarefa rampa{
    se(arredondar(inclinacao())==340 e ultra(2)>100)entao{
        velocidade = 100
        escrever(1, "RAMPAAAA!!!!")
        zerartemporizador()
        enquanto(temporizador()<1300)farei{obstaculo()}
        parar()
        esperar(2000)
        escrever(1, "RAMPA FINALIZADA")
        zerartemporizador()
    } senao {
        obstaculo()
    }
}
tarefa resgate{
    se(inclinacao()>0 e inclinacao()<350 e ultra(2)<40)entao{
        parar()
        acenderled("VERDE")
        velocidade = 200
        enquanto(inclinacao()!=0)farei{
            seguelinha()
        }
        alinhar()
        temp = falso
        rotacionar(1000, negativo(40))
        frente(300)
        esperar(500)
        rotacionar(1000, 40)
        tras(300)
        esperar(500)
        parar()
        abrir(1)
        baixar(1000)
        enquanto(verdadeiro)farei{
            parar()
            triangulo = triangulo + 1
            enquanto(ultra(1)>140)farei{frente(300)}
            parar()
            levantar(600)
            fechar(1)
            enquanto(luz(3)>12 e ultra(1)>35)farei{frente(300)}
			parar()
            se(cor(3)=="PRETO")entao{interromper()}
            rotacionar(1000, 40)
            frente(300)
            esperar(300)
            rotacionar(1000, 55)
            alinhar()
            abrir(1)
            baixar(600)
        }
        se(temvitima())entao{
            abrir(1)
            baixar(600)
            esperar(300)
            fechar(1)
            levantar(600)
        }
        enquanto(verdadeiro)farei{
            trasrotacao(1000, 30)
            rotacionar(1000, 90)
            alinhar()
            graus = direcao()
            abrir(1)
            baixar(600)
            zerartemporizador()
            enquanto(temporizador()<1300 e temvitima()==falso)farei{frente(300)}
            parar()
            se(temvitima()==verdadeiro)entao{
                frente(300)
                levantar(300)
                levantar(300)
                fechar(1)
                rotacionar(1000, 180)
                alinhar()
                enquanto(ultra(1)>30)farei{frente(300)}
                parar()
                rotacionar(1000, 90)
                enquanto(luz(3)>8)farei{frente(300)}
                parar()
                #abrir(1)
                baixar(600)
                esperar(500)
                #fechar(1)
                levantar(600)
                # Resgatar a vitima
            } senao {
                fechar(1)
                levantar(600)
                enquanto(ultra(2)>100)farei{direita(1000)}
                parar()
                se(ultra(2)<100)entao{
                    acenderled("VERMELHO")
                    parar()
                    rotacionar(1000, 95)
                    tras(300)
                    esperar(300)
                    parar()
                    abrir(1)
                    baixar(600)
                    zerartemporizador()
                    enquanto(temvitima()==falso)farei{
                        escrevernumero(1, temporizador())
                        frente(300)
                    }
                    recuar = temporizador()
                    zerartemporizador()
                    parar()
                    frente(300)
                    levantar(600)
                    parar()
                    fechar(1)
                    tras(300)
                    esperar(recuar)
                    parar()
                    enquanto(arredondar(direcao())!=graus + 180)farei{esquerda(1000)}
		            parar()
                    esperar(10000)
                }
            } # Verificação se tem vitima
        } # Aqui fecha o loop do resgate
    } senao {
        rampa()
    }
}

tarefa seperdeu{
    se(temporizador()>800 e temp==verdadeiro)entao{
		parar()
		zerartemporizador()
		enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1200)farei{
			se(ULTIMO==1)entao{
				direita(1000)
			} senao se (ULTIMO==2)entao{
				esquerda(1000)
			} senao {
				direita(1000)
			}
		}
		parar()
		se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
			zerartemporizador()
			enquanto(cor(2)=="BRANCO" e temporizador()<2400)farei{
				se(ULTIMO==1)entao{
					esquerda(1000)
				} senao se (ULTIMO==2)entao{
					direita(1000)
				} senao {
					esquerda(1000)
				}
			}
			zerartemporizador()
			se(cor(2)=="BRANCO")entao{
				se(ULTIMO==1)entao{
					direita(1000)
					esperar(1200)
				} senao se (ULTIMO==2)entao{
					esquerda(1000)
					esperar(1200)
				} senao {
					direita(1000)
					esperar(1200)
				}
				se(tempCont == 0)entao{
					tras(200)
					esperar(820)
					tempCont = tempCont + 1
					parar()
				}
			}
			zerartemporizador()
		}
	}senao {
		resgate()
	}
}
inicio
velocidadeatuador(150)
levantar(900)
zerartemporizador()

enquanto(verdadeiro)farei{
    seperdeu()
}
fim