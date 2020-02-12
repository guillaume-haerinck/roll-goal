using UnityEngine;
using Unity.Jobs;
using Unity.Entities;
using Unity.Mathematics;
using Unity.Transforms;

public class MovementSystem : JobComponentSystem
{
    protected override JobHandle OnUpdate(JobHandle inputDeps)
    {
        float deltaTime = Time.DeltaTime;

        JobHandle myJob = Entities.ForEach((ref Translation trans, in MotionComponent motion) => {
            trans.Value = motion.direction * motion.speed;
        }).Schedule(inputDeps);

        return myJob;
    }
}
