#include "Worker.hpp"
#include "Workshop.hpp"

int main()
{

	Worker workerA(15, 15, 15, 0, 0);
	Worker workerB(7, 23, 10, 0, 0);

	Workshop<Hammer> HammerWorkshop;
	Workshop<Shovel> ShovelWorkshop;
	Workshop<Tool> Workshop;

	Hammer hammer = Hammer();
	Shovel shovel = Shovel();

	workerA.giveTool(&hammer);
	workerA.giveTool(&shovel);
	workerB.giveTool(&hammer);
	workerB.giveTool(&shovel);

	workerA.useTool(&hammer);
	workerB.useTool(&hammer);

	HammerWorkshop.registerWorker(&workerB);
	ShovelWorkshop.registerWorker(&workerB);
	Workshop.registerWorker(&workerB);
	Workshop.registerWorker(&workerA);
	workerB.takeTool(&shovel);
}
