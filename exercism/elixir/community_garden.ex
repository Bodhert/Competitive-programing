# Use the Plot struct as it is provided
defmodule Plot do
  @enforce_keys [:plot_id, :registered_to]
  defstruct [:plot_id, :registered_to]
end



defmodule CommunityGarden do

  def start(opts \\ []) do
    Agent.start(fn  -> %{id: 0, list: []} end, opts)
  end

  def list_registrations(pid) do
    Agent.get(pid, fn %{list: list} -> list end)
  end

  def register(pid, register_to) do
    Agent.get_and_update(pid, fn %{id: id, list: list} = state ->
      id = id + 1
      plot = %Plot{plot_id: id, registered_to: register_to}
      {plot, %{state | id: id, list: [plot | list]}}
     end)
  end

  def release(pid, plot_id) do
    Agent.cast(pid, fn %{list: list} = state ->
      updated_list = Enum.filter(list, fn plot -> plot.plot_id != plot_id  end)
      %{state | list: updated_list}
    end )
  end

  def get_registration(pid, plot_id) do
    Agent.get(pid, fn %{list: list} ->
      Enum.find(list, {:not_found, "plot is unregistered"}, fn plot -> plot.plot_id == plot_id  end)
     end)
  end
end
