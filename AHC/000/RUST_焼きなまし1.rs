fn solve(input: &Input) -> Vec<usize> {
  //焼きなましの温度の始点
  const T0: f64 = 2e3;
  //焼きなましの温度の終点
  const T1: f64 = 6e2;
  //焼きなましのタイムリミット
  const TL: f64 = 1.9;
  //
  let mut rng = rand_pcg::Pcg64Mcg::new(890482);
  let mut state = State::new(input, (0..input.D).map(|_| rng.gen_range(0, 26)).collect());
  let mut cnt = 0;
  let mut T = T0;
  let mut best = state.score;
  let mut best_out = state.out.clone();
  //焼きなましの処理
  loop {
    //焼きなまし中の乱択回数
    cnt += 1;
    //乱択回数が100の倍数になったら時間が大丈夫か判定する
    if cnt % 100 == 0 {
      //t:タイムリミット1.9sに対する経過時間の割合(get_time()でプログラムの開始からの時間をとる)
      let t = get_time() / TL;
      //プログラム開始から1.9second経過している場合は焼きなましを終えて出力に移る
      if t >= 1.0 {
        break;
      }
      //焼きなましの現時点での温度(乱択時の悪化を受け入れるかどうかの確率)を現在の経過時間を用いて変動させる
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
