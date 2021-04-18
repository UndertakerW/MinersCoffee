#include "structures.h"


Core::Core(QString core_name, const QString& core_path, const QString& core_api)
{
    name = core_name;
    path = core_path;
    api = core_api;
}

Coin::Coin(QString coin_name)
{
    name = coin_name;
}

Pool::Pool(QString pool_name)
{
    name = pool_name;
}

void Coin::AddCore(Core* core, const QString& cmd)
{
    cores.append(core);
    core->cmds[this] = cmd;
}

void Coin::AddPool(Pool* pool, const QString& cmd)
{
    pools.append(pool);
    pool->cmds[this] = cmd;
}
