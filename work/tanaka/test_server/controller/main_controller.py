from service.serversock import Serversock

class MainController:

	@staticmethod
	def hello():
		Serversock.create_server_socket('127.0.0.1',4000)
		Serversock.accept_loop()
		
		