defmodule TakeANumber do
  use TypeCheck

  @type! msg() :: :report_state | :take_a_number | :stop | any()

  @spec! start() :: pid
  def start() do
    spawn(fn -> loop(0) end)
  end

  @spec! loop(integer()) :: no_return # ask how can we pass the spec test
  def loop(state) do
    new_state =
      receive do
        message -> proccess_message(state, message)
      end

    loop(new_state)

  end

  ## ask how can we pass the spec test
  @spec! proccess_message(integer(), {msg(), pid} | msg() | any()) :: integer() | no_return() | any()
  def proccess_message(state, {:report_state, caller}) do
    send(caller, state)
    state
  end

  def proccess_message(state, {:take_a_number, caller}) do
    new_state = state + 1
    send(caller, new_state)
    new_state
  end

  def proccess_message(_state, :stop) do
    Process.exit(self(), :normal)
  end

  def proccess_message(state, _) do
    state
  end






end
