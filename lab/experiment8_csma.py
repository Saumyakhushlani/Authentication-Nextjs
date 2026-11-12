import random

PROTOCOLS = ('CSMA/CD', 'NON-PERSISTENT', '1-PERSISTENT', 'P-PERSISTENT')


def simulate(protocol, n_stations=4, frames_each=2, frame_time=3,
             p=0.4, seed=7, max_slots=2000):
    rng = random.Random(seed)
    frames = {s: frames_each for s in range(1, n_stations + 1)}
    wait_until = {s: 0 for s in frames}
    attempts = {s: 0 for s in frames}
    busy_until = 0
    successes = collisions = 0
    log = [f'=== {protocol} ===']

    for t in range(max_slots):
        if not any(frames.values()):
            break
        idle = t >= busy_until
        ready = [s for s in frames if frames[s] > 0 and t >= wait_until[s]]
        transmitting = []

        for s in ready:
            if not idle:
                if protocol == 'NON-PERSISTENT':
                    delay = rng.randint(1, 5)
                    wait_until[s] = t + delay
                    log.append(f't={t:3d}: S{s} senses BUSY; waits {delay} slots')
                continue

            if protocol == 'P-PERSISTENT' and rng.random() >= p:
                wait_until[s] = t + 1
                log.append(f't={t:3d}: S{s} defers to next slot (p={p})')
            else:
                transmitting.append(s)

        if len(transmitting) == 1:
            s = transmitting[0]
            frames[s] -= 1
            attempts[s] = 0
            successes += 1
            busy_until = t + frame_time
            log.append(f't={t:3d}: S{s} SUCCESS (frames remaining: {frames[s]})')
        elif len(transmitting) > 1:
            collisions += 1
            busy_until = t + 1
            label = 'collision detected; JAM' if protocol == 'CSMA/CD' else 'collision'
            stations = ', '.join(f'S{s}' for s in transmitting)
            log.append(f't={t:3d}: {label} between {stations}')
            for s in transmitting:
                attempts[s] += 1
                k = min(attempts[s], 10)
                delay = rng.randint(0, 2**k - 1)
                wait_until[s] = t + 1 + delay
                log.append(f'         S{s} backs off {delay} slots')
    else:
        log.append('Simulation stopped: maximum time reached')

    total_time = max(t + 1, busy_until)
    throughput = successes * frame_time / total_time if total_time else 0
    result = dict(protocol=protocol, successes=successes, collisions=collisions,
                  total_time=total_time, throughput=throughput,
                  complete=not any(frames.values()))
    log.append(f'SUMMARY: successes={successes}, collisions={collisions}, '
               f'time={total_time} slots, throughput={throughput:.2f}')
    return result, log


if __name__ == '__main__':
    print('Experiment 8: CSMA Protocol Simulation')
    print('4 stations, 2 frames each, frame time=3 slots, p=0.4')
    for protocol in PROTOCOLS:
        result, log = simulate(protocol)
        print('\n'.join(log))
