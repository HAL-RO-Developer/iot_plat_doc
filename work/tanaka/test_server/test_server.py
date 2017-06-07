from util.args import args
from service.dispatch import dispatch

def main():
	disp = dispatch(args)
	disp.run()

if __name__ == '__main__':
    main()