from util.args import args
from service.dispatch import Dispatch

def main():
	disp = Dispatch(args)
	disp.run()

if __name__ == '__main__':
    main()