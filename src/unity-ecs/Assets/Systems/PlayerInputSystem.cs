using UnityEngine;
using Unity.Jobs;
using Unity.Entities;
using Unity.Mathematics;

[AlwaysSynchronizeSystem]
public class PlayerInputSystem : JobComponentSystem
{
    protected override JobHandle OnUpdate(JobHandle inputDeps)
    {
        Entities.ForEach((ref MotionComponent motion, in InputComponent input) => {
            motion.direction.x += Input.GetKey(input.forwardKey) ? 1f : 0;
            motion.direction.x -= Input.GetKey(input.backKey) ? 1f : 0;
        }).Run();

        return default;
    }
}
