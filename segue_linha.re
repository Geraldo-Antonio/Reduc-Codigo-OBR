tarefa seguelinha {
    // Verifica se a luz no sensor 1 é baixa
    se (luz(1) < 50) entao {
        // Verifica se a luz no sensor 2 é baixa
        se (luz(2) < 50) entao {
            escrever(1, "DOIS PRETOS")  // Escreve no display 1 a mensagem "DOIS PRETOS"
            escrevernumero(2, ULTIMO)  // Escreve no display 2 o valor da variável ULTIMO
            frente(150)  // Move para frente com velocidade 150
            esperar(250)  // Espera por 250 milissegundos

            // Verifica se uma das cores nos sensores 1 ou 2 é verde
            se (cor(1) == "VERDE" ou cor(2) == "VERDE") entao {
                frente(150)  // Move para frente com velocidade 150
                esperar(300)  // Espera por 300 milissegundos
            }

            // Verifica o valor da variável ULTIMO
            se (ULTIMO == 2) entao {
                zerartemporizador()  // Zera o temporizador
                enquanto (temporizador() < 1800) farei {  // Executa o loop enquanto o temporizador for menor que 1800
                    // Verifica se nenhuma das cores nos sensores 1 e 2 é preto
                    se (cor(1) != "PRETO" e cor(2) != "PRETO") entao {
                        direita(1000)  // Gira para a direita com velocidade 1000
                    } senao {
                        interromper()  // Interrompe a execução
                    }
                }
                parar()  // Para a execução
                // Verifica se as cores nos sensores 1 e 2 são brancas
                se (cor(1) == "BRANCO" e cor(2) == "BRANCO") entao {
                    tras(300)  // Move para trás com velocidade 300
                    esperar(150)  // Espera por 150 milissegundos
                    zerartemporizador()  // Zera o temporizador
                    enquanto (temporizador() < 3600) farei {  // Executa o loop enquanto o temporizador for menor que 3600
                        // Verifica se nenhuma das cores nos sensores 1 e 2 é preto
                        se (cor(1) != "PRETO" e cor(2) != "PRETO") entao {
                            esquerda(1000)  // Gira para a esquerda com velocidade 1000
                        } senao {
                            interromper()  // Interrompe a execução
                        }
                    }
                    parar()  // Para a execução
                    // Verifica se o temporizador é maior que 3600
                    se (temporizador() > 3600) entao {
                        direita(1000)  // Gira para a direita com velocidade 1000
                        esperar(3350)  // Espera por 3350 milissegundos
                    }
                }
            } senao se (ULTIMO == 1) entao {
                zerartemporizador()  // Zera o temporizador
                enquanto (temporizador() < 1800) farei {  // Executa o loop enquanto o temporizador for menor que 1800
                    // Verifica se nenhuma das cores nos sensores 1 e 2 é preto
                    se (cor(1) != "PRETO" e cor(2) != "PRETO") entao {
                        esquerda(1000)  // Gira para a esquerda com velocidade 1000
                    } senao {
                        interromper()  // Interrompe a execução
                    }
                }
                parar()  // Para a execução
                // Verifica se as cores nos sensores 1 e 2 são brancas
                se (cor(1) == "BRANCO" e cor(2) == "BRANCO") entao {
                    tras(300)  // Move para trás com velocidade 300
                    esperar(150)  // Espera por 150 milissegundos
                    zerartemporizador()  // Zera o temporizador
                    enquanto (temporizador() < 3600) farei {  // Executa o loop enquanto o temporizador for menor que 3600
                        // Verifica se nenhuma das cores nos sensores 1 e 2
