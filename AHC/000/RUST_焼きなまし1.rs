fn solve(input: &Input) -> Vec<usize> {
  const T0: f64 = 2e3;
  const T1: f64 = 6e2;
  const TL: f64 = 1.9;
  let mut rng = rand_pcg::Pcg64Mcg::new(890482);
  let mut state = State::new(input, (0..input.D).map(|_| rng.gen_range(0, 26)).collect());
  let mut cnt = 0;
  let mut T = T0;
  let mut best = state.score;
  let mut best_out = state.out.clone();
  loop {
    cnt += 1;
    if cnt % 100 == 0 {
      let t = get_time() / TL;
      if t >= 1.0 {
        break;
      }
      T = T0.powf(1.0 - t) * T1.powf(t);
    }
    let old_score = state.score;
    if rng.gen_bool(0.5) {
      let d = rng.gen_range(0, input.D);
      let old = state.out[d];
      state.change(input, d, rng.gen_range(0, 26));
      if old_score > state.score && !rng.gen_bool(f64::exp((state.score - old_score) as f64 / T)) {
        state.change(input, d, old);
      }
    } else {
      let d1 = rng.gen_range(0, input.D - 1);
      let d2 = rng.gen_range(d1 + 1, (d1 + 16).min(input.D));
      let (a, b) = (state.out[d1], state.out[d2]);
      state.change(input, d1, b);
      state.change(input, d2, a);
      if old_score > state.score && !rng.gen_bool(f64::exp((state.score - old_score) as f64 / T)) {
        state.change(input, d1, a);
        state.change(input, d2, b);
      }
    }
    if best.setmax(state.score) {
      best_out = state.out.clone();
    }
  }
  best_out
}
