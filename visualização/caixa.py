import pygame

class Caixa():
	def __init__(self,largura,altura,cor,animacao,tela):
		self.largura = largura
		self.altura = altura
		self.cor = cor
		
		self.animacao = animacao
		self.tela = tela

		self.posicaoAtual = 0
		self.offsetX = tela.get_width() / 2
		
		self.retangulo = pygame.Rect(animacao[self.posicaoAtual][0]-largura/2+self.offsetX,animacao[self.posicaoAtual][1]+altura/2,largura,altura)		
		
		
	def desenharProxPosicao(self):
		
		pygame.draw.rect(self.tela,self.cor,self.retangulo)		
		self.posicaoAtual = (self.posicaoAtual + 1)%len(self.animacao)		
		self.retangulo.x, self.retangulo.y = (self.animacao[self.posicaoAtual][0]+self.offsetX-self.largura/2,self.animacao[self.posicaoAtual][1]+self.altura/2)
		print str(self.retangulo.x) + " " + str(self.retangulo.y)
