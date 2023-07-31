defmodule RPNCalculatorInspection do
  def start_reliability_check(calculator, input) do
    %{input: input, pid: spawn_link(fn -> calculator.(input) end)}
  end

  def await_reliability_check_result(%{pid: pid, input: input}, results) do
    result =
      receive do
        {:EXIT, from, :normal} when from == pid ->
          Map.merge(results, %{input => :ok})

        {:EXIT, from, _reason} when from == pid ->
          Map.merge(results, %{input => :error})
      after
        100 ->
          Map.merge(results, %{input => :timeout})
      end

    result
  end

  def reliability_check(calculator, inputs) do
    old_value = Process.flag(:trap_exit, true)

    result =
    inputs
    |> Enum.map(fn input ->  start_reliability_check(calculator, input) end)
    |> Enum.reduce(%{}, fn task, acc -> await_reliability_check_result(task, acc) end)

    Process.flag(:trap_exit, old_value)
    result
  end

  def correctness_check(calculator, inputs) do
    inputs
    |> Enum.map(fn input -> Task.async(fn -> calculator.(input) end)  end)
    |> Enum.map(fn task -> Task.await(task, 100) end)
  end
end
