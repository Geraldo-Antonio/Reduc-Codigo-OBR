booleano aindanaoachou = verdadeiro

tarefa resgate{
	se (ultra(1) >= 350) entao{
		escrever(1, "Tipo 2")
		enquanto(aindanaoachou) farei{
			se(luz(3) <= 10) entao{
				escrever(2, "Posição 1")
                triangulo = 1
				aindanaoachou = falso
			}senao se(arredondar(ultra(2)) > 175 e arredondar(ultra(2)) < 190) entao{
				escrevernumero(3, ultra(2))
				se (ultra(2) > 175) entao{
					tras(200)
					esperar(350)
					se(ultra(2) > 500) entao{
							frente(200)
						esperar(350)
						escrever(3, "Falso positivo")
					} senao {
							frente(200)
						esperar(350)
						se (ultra(1) < 100) entao{
								escrever(2, "Posição 2")
                                triangulo = 2
						} senao {
								escrever(2, "Posição 3")
                                triangulo = 3
						}
						aindanaoachou = falso
						rotacionar(1000, 90)
					}
				}
			}senao {
				frente(400)
			}
		}
	} senao {		
		escrever(1, "Tipo 1")
		enquanto(aindanaoachou) farei{
			se(luz(3) <= 10) entao{
				escrever(2, "Posição 1")
                triangulo = 1
				aindanaoachou = falso
			}senao se(arredondar(ultra(2)) > 290 e arredondar(ultra(2)) < 305) entao{
				se (ultra(2) > 290) entao{
					tras(200)
					esperar(350)
					se(ultra(2) > 500) entao{
							frente(200)
						esperar(350)
						escrever(3, "Falso positivo")
					} senao {
							frente(200)
						esperar(350)
						se (ultra(1) < 100) entao{
								escrever(2, "Posição 2")
                                triangulo = 2
						} senao {
								escrever(2, "Posição 3")
                                triangulo = 3
						}
						aindanaoachou = falso
						#rotacionar(1000, 90)
					}
				}
			}senao {
				frente(300)
			}
		}
	}
}

# Triangulo atual

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

# PROCURAR VITIMAS ATUAL
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
}

tarefa triangulo3{
    enquanto(verdadeiro)farei{
    zerartemporizador()
    escrever(1, "PROCURANDO VITIMAS")
    # Vai para tras apos achar o trinagulo e procura vitimas
    ULTRA2 = ultra(2) - 3
    zerartemporizador()
    enquanto(temporizador()<1800 e ultra(2)>ULTRA2 e toque(1)==falso)farei{
        escrevernumero(ULTRA2)
        se(ultra(2)>ULTRA2)entao{
            ULTRA2 = ultra(2)
        }
        frente(300)
    }
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
    }
}
}

tarefa triangulo2{

}

tarefa triangulo1{

}