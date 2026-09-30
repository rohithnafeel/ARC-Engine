void HierarchyPanel::Render()
{
    ImGui::Begin("Hierarchy");

    ImGui::Text("Scene");

    if (ImGui::TreeNode("Entities"))
    {
        ImGui::BulletText("Player");
        ImGui::BulletText("Camera");
        ImGui::BulletText("Light");

        ImGui::TreePop();
    }

    ImGui::End();
}