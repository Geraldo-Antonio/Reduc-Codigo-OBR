numero saida = 0
numero velocidade = 110
booleano temp = verdadeiro
numero tempCont = 0
numero ULTIMO = 0
numero triangulo = 0
numero recuar = 0
numero graus = 0
numero vitimapos = 0
numero antigapos = 0
numero ULTRA2 = 0
booleano V2 = falso
tarefa alinhar {
    #escrevernumero(2, direcao())
	se(direcao()>230 e direcao()<300)entao{
	    #escrever(1, "270")
	    rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=270)farei{esquerda(500)}
		parar()
	} senao se(direcao()>300 ou direcao()<40)entao{
		#escrever(1, "0")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=0)farei{esquerda(500)}
		parar()
	} senao se(direcao()>40 e direcao()<130)entao{
		#escrever(1, "90")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=90)farei{esquerda(500)}
		parar()
	} senao se(direcao()>130 e direcao()<230)entao{
		#escrever(1, "180")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=180)farei{esquerda(500)}
		parar()
	}
}

tarefa seguelinha{
    se(luz(1)<50)entao{
        se(luz(2)<50) entao{
            escrever(1, "DOIS PRETOS")
            escrevernumero(2, ULTIMO)
            frente(150)
            esperar(300)
            se(cor(1)=="VERDE" ou cor(2)=="VERDE")entao{frente(150) esperar(300)}
            se(ULTIMO == 2)entao{
                zerartemporizador()
                enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1800)farei{direita(1000)}
                parar()
                se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
                    enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{esquerda(1000)}
                    parar()
                }
            } senao se(ULTIMO == 1)entao{
                zerartemporizador()
                enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1800)farei{esquerda(1000)}
                parar()
                se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
                    enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{direita(1000)}
                    parar()
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

tarefa verde{
	se(cor(1)=="VERDE")entao{
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
            enquanto(cor(2)=="BRANCO" e temporizador()<300)farei{frente(100)}
            parar()
            frente(300)
            esperar(300)
            rotacionar(1000, negativo(55))
            zerartemporizador()
            enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
            parar()
		
	    }
	zerartemporizador()
	} senao{
		verde()
 	}
}
tarefa rampa{
    se(arredondar(inclinacao())==340 e ultra(2)>100)entao{
        escrever(1, "ELEVAÇÂO DETECTADA")
        zerartemporizador()
        enquanto(arredondar(inclinacao())<345)farei{obstaculo()}
        parar()
        antigapos = arredondar(inclinacao())
        esperar(2000)
        escrever(1, "RAMPA FINALIZADA")
        se(antigapos == arredondar(inclinacao()))entao{
            escrever(2, "RAMPA")
            escrever(3, "CONTINUANDO RAMPA")
            zerartemporizador()
            enquanto(temporizador()<2500)farei{obstaculo()}
            parar()
            frente(300)
            esperar(100)
        }
        zerartemporizador()
        #limparconsole()
    } senao {
        obstaculo()
    }
}
tarefa resgate{
    se((inclinacao()>300 e inclinacao()<345) e ultra(2)<40)entao{
        parar()
        acenderled("VERDE")
        escrever(1, "POSSIVEL RESGATE")
        zerartemporizador()
        enquanto(temporizador()<500)farei{
            rampa()
        }
        se((inclinacao()>300 e inclinacao()<345) e ultra(2)<40)entao{
            escrever(1, "RESGATE CONFIRMADO, SUBINDO RAMPA")
            velocidade = 200
            enquanto(arredondar(inclinacao())!=0 e ultra(2)<70)farei{
                seguelinha()
            }
            escrever(1, "RAMPA COMPLETA")
            frente(300)
            esperar(300)
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
            se(ultra(2)>500)entao{saida = 3}
            se(ultra(1)>500)entao{saida = 1}
            escrever(1, "COMEÇAR A PROCURAR TRIANGULO")
            enquanto(verdadeiro)farei{
                parar()
                triangulo = triangulo + 1
                enquanto(ultra(1)>155)farei{frente(300)}
                parar()
                frente(300)
                levantar(300)
                parar()
                fechar(1)
                levantar(300)
                enquanto(luz(3)>8 e ultra(1)>35)farei{frente(300)}
                parar()
                se(triangulo==1 e ultra(2)>500)entao{saida = 2}
                senao se(triangulo==2 e ultra(2)>500)entao{saida = 3}
                se(cor(3)=="PRETO")entao{interromper()}
                rotacionar(1000, 40)
                frente(300)
                esperar(300)
                rotacionar(1000, 55)
                alinhar()
                abrir(1)
                baixar(600)
                zerartemporizador()
                enquanto(temporizador()<400 e toque(1)==falso)farei{tras(300)}
                parar()
                se(toque(1)==falso e triangulo==1)entao{saida=1}
                senao se(toque(1)==falso e triangulo==2)entao{saida=2}
            }
            escrever(1, "TRIANGULO ENCONTRADO")
            se(temvitima()==verdadeiro)entao{
                parar()
                abrir(1)
                girarbaixo(1000)
                baixar(600)
                enquanto(temvitima())farei{esperar(1)}
                esperar(500)
                fechar(1)
                levantar(600)
                girarcima(1000)
            }
            enquanto(verdadeiro)farei{
                zerartemporizador()
                escrever(1, "PROCURANDO VITIMAS")
                # Vai para tras apos achar o trinagulo e procura vitimas
                se(ultra(2)>=230)entao{
                    ULTRA2 = ultra(2) - 3
                } senao { ULTRA2 = 230}
                zerartemporizador()
                enquanto(temporizador()<1800 e ultra(2)>ULTRA2 e toque(1)==falso)farei{tras(300)}
                parar()
                escrever(1, "VITIMA ENCONTRADA")
                se(ultra(2)<ULTRA2)entao{
                    #escrevernumero(1, ultra(2))
                    vitimapos = ultra(2)
                    escrevernumero(3, vitimapos)
                    enquanto(ultra(2)<ULTRA2)farei{tras(300)}
                    parar()
                    frente(300)
                    esperar(200)
                    se(ultra(2)<vitimapos)entao{
                        vitimapos = ultra(2)
                    }
                    rotacionar(1000, 90)
                    alinhar()
                    se(vitimapos<40)entao{
                        frente(100)
                        esperar(1200)
                        tras(300)
                        esperar(300)
                    }
                    abrir(1)
                    baixar(600)
                    escrever(1, "INDO ATRÁS DA VITIMA")
                    zerartemporizador()
                    enquanto(temvitima()==falso e ultra(1)>45 e temporizador()<5000)farei{frente(200)}
                    parar()
                    se(ultra(1)<45)entao{
                        escrever(1, "PAREDE")
                        fechar(1)
                        levantar(600)
                        enquanto(toque(1)==falso)farei{tras(300)}
                        parar()
                        rotacionar(1000, negativo(90))
                        enquanto(cor(3)!="PRETO")farei{frente(300)}
                        parar()
                        se(temvitima())entao{
                            parar()
                            girarbaixo(1000)
                            abrir(1)
                            baixar(600)
                            enquanto(temvitima())farei{esperar(1)}
                            esperar(500)
                            fechar(1)
                            levantar(600)
                            girarcima(1000)
                        }
                    } senao se(temvitima())entao{
                        escrever(1, "FAZENDO RESGATE DA VITIMA")
                        frente(300)
                        levantar(300)
                        parar()
                        fechar(1)
                        levantar(300)
                        parar()
                        esperar(500)
                        rotacionar(1000, 180)
                        alinhar()
                        enquanto(ultra(1)>30)farei{frente(300)}
                        parar()
                        rotacionar(1000, 90)
                        alinhar()
                        enquanto(luz(3)>8)farei{frente(300)}
                        parar()
                        #tras(300)
                        #esperar(200)
                        parar()
                        girarbaixo(1000)
                        abrir(1)
                        baixar(600)
                        enquanto(temvitima())farei{esperar(1)}
                        esperar(500)
                        fechar(1)
                        levantar(600)
                        girarcima(1000)
                        # Resgatar a vitima
                    } senao {
                        fechar(1)
                        levantar(600)
                        enquanto(toque(1)==falso)farei{tras(300)}
                        parar()
                        rotacionar(1000, negativo(90))
                        alinhar()
                    }
                } senao {
                    #Foi para tras e não achou nenhuma vitima então vai em direção do meio da arena e no caminha procura vitimas
                    escrever(1, "NENHUMA VITIMA ENCONTRADA PROCURAR DO OUTRO LADO")
                    rotacionar(1000, negativo(90))
                    alinhar()
                    graus = arredondar(direcao())
                    enquanto(ultra(1)<80)farei{tras(300)}
                    parar()
                    ULTRA2 = ultra(2) - 1
                    zerartemporizador()
                    enquanto(temporizador()<1800 e temvitima()==falso e ultra(2)>ULTRA2)farei{tras(300)}
                    parar()
                    se(ultra(2)<ULTRA2)entao{
                        #Achou vitimas antes de chegar no meio
                        escrever(1, "VITIMA ENCONTRADA")
                        #escrevernumero(1, ultra(2))
                        vitimapos = ultra(2)
                        tras(300)
                        esperar(100)
                        parar()
                        levantar(600)
                        fechar(1)
                        rotacionar(1000, 90)
                        alinhar()
                        #se(vitimapos<30)entao{
                            #tras(300)
                            #esperar(300)
                        #}
                        abrir(1)
                        baixar(600)
                        escrever(1, "INDO PARA FRENTE ATÈ CHEGAR NA VITIMA")
                        zerartemporizador()
                        enquanto(temvitima()==falso e ultra(1)>45)farei{frente(300)}
                        parar()
                        escrever(1, "VERIFICANDO SE VITIMA FOI PEGA")
                        recuar = temporizador()
                        se(temvitima())entao{
                            frente(300)
                            levantar(400)
                            parar()
                            fechar(1)
                            levantar(400)
                            parar()
                            esperar(500)
                            escrever(1, "LEVANDO A VITIMA ATÈ O TRIANGULO")
                            tras(300)
                            esperar(recuar / 2)
                            rotacionar(1000, negativo(90))
                            alinhar()
                            enquanto(ultra(1)>30)farei{frente(300)}
                            parar()
                            rotacionar(1000, 90)
                            alinhar()
                            enquanto(luz(3)>8)farei{frente(300)}
                            parar()
                            #tras(300)
                            #esperar(200)
                            parar()
                            girarbaixo(1000)
                            abrir(1)
                            baixar(600)
                            enquanto(temvitima())farei{esperar(1)}
                            esperar(500)
                            fechar(1)
                            levantar(600)
                            girarcima(1000)
                            # Resgatar a vitima
                        } senao {
                            tras(300)
                            esperar(recuar)
                            rotacionar(1000, negativo(90))
                        }
                    }senao se(temvitima()==verdadeiro)entao{
                        #achou vitimas com a garra enquanto ia
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
                        esperar(600)
                        #fechar(1)
                        levantar(600)
                        # Resgatar a vitima
                    } senao {
                        #chegou ao meio e vai girar procurando vitimas
                        #IR PARA o saida = 0
                        escrever(1, "NENHUMA VITIMA ECONTRADA INDO PARA A SAIDA")
                        limparconsole()
                        #escrevernumero(1, saida)
                        #escrevernumero(2, triangulo)
                        velocidade = 110
                        temp = verdadeiro
                        se(triangulo==1 e ultra(2)>500)entao{saida = 2}
                        se(triangulo==2 e ultra(2)>500)entao{saida = 3}
                        se(triangulo==1)entao{
                            se(saida==2)entao{
                                rotacionar(1000, negativo(90))
                                enquanto(ultra(1)<280)farei{tras(300)}
                                parar()
                                rotacionar(1000, 180)
                                enquanto(cor(1)!="VERMELHO" e cor(2)!="VERMELHO")farei{rampa()}
                                parar()
                                frente(300)
                                esperar(300)
                                parar()
                                esperar(10000)
                            } senao se(saida==3)entao{
                                rotacionar(1000, negativo(90))
                                se(ultra(1)<36)entao{
                                    enquanto(ultra(1)<36)farei{tras(300)}
                                    parar()
                                } senao {
                                    enquanto(ultra(1)>36)farei{frente(300)}
                                    parar()
                                }
                                rotacionar(1000, negativo(90))
                                alinhar()
                                enquanto(ultra(2)<500)farei{frente(300)}
                                parar()
                                tras(300)
                                esperar(400)
                                enquanto(cor(1)!="VERMELHO" e cor(2)!="VERMELHO")farei{rampa()}
                                parar()
                                frente(300)
                                esperar(300)
                                parar()
                                esperar(10000)
                            }
                        } senao se(triangulo==2)entao{
                            se(saida==1)entao{
                                enquanto(ultra(1)>40)farei{frente(300)}
                                parar()
                                rotacionar(1000, negativo(90))
                                alinhar()
                                enquanto(ultra(2)<500)farei{frente(300)}
                                parar()
                                enquanto((cor(1)!="VERDE" e cor(2)!="VERDE") e (cor(1)!="CIANO" e cor(2)!="CIANO"))farei{tras(200)}
                                parar()
                                frente(300)
                                esperar(200)
                                enquanto(cor(1)!="VERMELHO" e cor(2)!="VERMELHO")farei{rampa()}
                                parar()
                                frente(300)
                                esperar(200)
                                parar()
                                esperar(10000)
                            } senao se(saida == 3)entao{
                                alinhar()
                                frente(300)
                                esperar(300)
                                rotacionar(1000, 90)
                                enquanto(toque(1)==falso)farei{tras(300)}
                                parar()
                                frenterotacao(1000, 125)
                                enquanto(cor(1)!="VERMELHO" e cor(2)!="VERMELHO")farei{rampa()}
                                parar()
                                frente(300)
                                esperar(200)
                                parar()
                                esperar(10000)
                            }
                        } senao se(triangulo==3) entao{
                            se(saida==1)entao{
                                rotacionar(1000, negativo(90))
                                frente(300)
                                esperar(100)
                                se(ultra(1)<35)entao{
                                    enquanto(ultra(1)<35)farei{tras(300)}
                                    parar()
                                } senao se(ultra(1)>35)entao{
                                    enquanto(ultra(1)>35)farei{frente(300)}
                                    parar()
                                }
                                rotacionar(1000, negativo(90))
                                enquanto(ultra(2)<500)farei{frente(300)}
                                parar()
                                enquanto((cor(1)!="VERDE" e cor(2)!="VERDE") e (cor(1)!="CIANO" e cor(2)!="CIANO"))farei{tras(200)}
                                parar()
                                frente(300)
                                esperar(200)
                                enquanto(cor(1)!="VERMELHO" e cor(2)!="VERMELHO")farei{rampa()}
                                parar()
                                frente(300)
                                esperar(200)
                                parar()
                                esperar(10000)
                            } senao se(saida==2)entao{
                                escrever(3, "ASOIDPAJHSOIDA")
                                enquanto(ultra(1)>40)farei{frente(300)}
                                parar()
                                rotacionar(1000, negativo(90))
                                frente(300)
                                esperar(300)
                                enquanto(cor(1)!="VERMELHO" e cor(2)!="VERMELHO")farei{rampa()}
                                parar()
                                frente(300)
                                esperar(200)
                                parar()
                                esperar(10000)
                            }
                        }
                    } # Verificação se tem vitima
                }
            } # Aqui fecha o loop do resgate
        }
    } senao {
        rampa()
    }
}

tarefa seperdeu{
    se(temporizador()>1000 e temp==verdadeiro)entao{
		parar()
		zerartemporizador()
		enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1300)farei{
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
			enquanto(cor(2)=="BRANCO" e temporizador()<2600)farei{
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
					esperar(1300)
				} senao se (ULTIMO==2)entao{
					esquerda(1000)
					esperar(1300)
				} senao {
					direita(1000)
					esperar(1300)
				}
				se(tempCont == 0)entao{
                    zerartemporizador()
                    enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1500)farei{tras(150)}
                    parar()
					tras(150)
                    esperar(300)
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
    se(cor(1)=="VERMELHO" ou cor(2)=="VERMELHO")entao{
        enquanto(cor(1)!="PRETO" e cor(2)!="PRETO")farei{tras(200)}
        parar()
    } senao {
        seperdeu()
    }
}
fim