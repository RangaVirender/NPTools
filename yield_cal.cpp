class MyMainFrame : public TGMainFrame
{
    private:
    TGGroupFrame *grid_frame_1;  
    TGGroupFrame *grid_frame_2;  
    TGGroupFrame *grid_frame_3;  
    TGGroupFrame *grid_frame_4;  
    TGTextButton *cal_yield_button; 
    TGTextButton *exit_button; 
    TGTextView   *text_output; 
    TGLabel      *label;
    TGLabel      *proj_charge_state_label;
    TGLabel      *total_charge_incident_label;
    TGLabel      *total_no_of_proj_label;
    TGLabel      *target_mass_label;
    TGLabel      *target_density_label;
    TGLabel      *det_radius_label;
    TGLabel      *det_dis_label;
    TGLabel      *det_eff_label;
    TGLabel      *rxn_crxn_label;
    
    TGNumberEntry *proj_charge_state_entry;
    TGNumberEntry *total_charge_incident_entry;
    TGNumberEntry *target_mass_entry;
    TGNumberEntry *target_density_entry;
    TGNumberEntry *det_radius_entry;
    TGNumberEntry *det_dis_entry;
    TGNumberEntry *det_eff_entry;
    TGNumberEntry *rxn_crxn_entry;
    
    TGString total_no_of_proj_string;

    int total_charge_incident_int;
    double total_no_of_proj_double;
    int proj_charge_state_int;
    
    public:
    MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
    virtual ~MyMainFrame();
    void cal_yield_button_clicked();
    void update_text_output();  
    void exit_button_clicked();
    void OnValueSet(); 
    virtual void CloseWindow(); 
    
};

// Callback function when value changes
//void MyMainFrame::OnValueSet()
//{   
 //   proj_integrated_current_int = proj_integrated_current_entry->GetIntNumber();
 //   std::cout << "proj_integrated_current_int: " << proj_integrated_current_int << std::endl;
//}


MyMainFrame::MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h) : TGMainFrame(p, w, h) 
{
    grid_frame_1 = new TGGroupFrame(this, "Projectile parameters", kHorizontalFrame);
   
    proj_charge_state_label = new TGLabel(grid_frame_1, "Projectile charge state");
    grid_frame_1->AddFrame(proj_charge_state_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    proj_charge_state_entry = new TGNumberEntry(grid_frame_1, 1, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    proj_charge_state_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_1->AddFrame(proj_charge_state_entry, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    total_charge_incident_label = new TGLabel(grid_frame_1, "Total charge incident (nano Coulomb)");
    grid_frame_1->AddFrame(total_charge_incident_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    total_charge_incident_entry = new TGNumberEntry(grid_frame_1, 1, 8, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    total_charge_incident_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    // Connect the value change signal to the callback function
   // proj_integrated_current_entry->Connect("ValueSet()","MyMainFrame",this, "OnValueSet()");

    grid_frame_1->AddFrame(total_charge_incident_entry, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    total_no_of_proj_label = new TGLabel(grid_frame_1, "No of projectiles: ");
    grid_frame_1->AddFrame(total_no_of_proj_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    grid_frame_2 = new TGGroupFrame(this, "Target parameters", kHorizontalFrame);
    
    target_mass_label = new TGLabel(grid_frame_2, "Target Mass no");
    grid_frame_2->AddFrame(target_mass_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    target_mass_entry = new TGNumberEntry(grid_frame_2, 1, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    target_mass_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_2->AddFrame(target_mass_entry, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    target_density_label = new TGLabel(grid_frame_2, "Target density");
    grid_frame_2->AddFrame(target_density_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    target_density_entry = new TGNumberEntry(grid_frame_2, 1, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    target_density_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_2->AddFrame(target_density_entry, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    grid_frame_3 = new TGGroupFrame(this, "Detector geometry parameters", kHorizontalFrame);
    
    det_radius_label = new TGLabel(grid_frame_3, "Detector Radius");
    grid_frame_3->AddFrame(det_radius_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    det_radius_entry = new TGNumberEntry(grid_frame_3, 1, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    det_radius_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_3->AddFrame(det_radius_entry, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    det_dis_label = new TGLabel(grid_frame_3, "Detector distance");
    grid_frame_3->AddFrame(det_dis_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    det_dis_entry = new TGNumberEntry(grid_frame_3, 1, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    det_dis_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_3->AddFrame(det_dis_entry, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    det_eff_label = new TGLabel(grid_frame_3, "Detector efficiency");
    grid_frame_3->AddFrame(det_eff_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    det_eff_entry = new TGNumberEntry(grid_frame_3, 1, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    det_eff_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_3->AddFrame(det_eff_entry, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    

    grid_frame_4 = new TGGroupFrame(this, "Calculate", kHorizontalFrame);

    rxn_crxn_label = new TGLabel(grid_frame_4, "Reaction cross-section(milli barn)");
    grid_frame_4->AddFrame(rxn_crxn_label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    rxn_crxn_entry = new TGNumberEntry(grid_frame_4, 1, 2, -1, TGNumberFormat::kNESInteger);//default value, max digits, ID 
    rxn_crxn_entry->SetLimits(TGNumberFormat::kNELLimitMin, 1);
    grid_frame_4->AddFrame(rxn_crxn_entry, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    label = new TGLabel(grid_frame_4, "........................");
    label->SetTextColor(TColor::RGB2Pixel(255, 0, 0));
    grid_frame_4->AddFrame(label, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));

    cal_yield_button = new TGTextButton(grid_frame_4, "Calculate");
    cal_yield_button->Connect("Clicked()", "MyMainFrame", this, "cal_yield_button_clicked()"); // Connect to click handler
    grid_frame_4->AddFrame(cal_yield_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));

    exit_button = new TGTextButton(grid_frame_4, "Exit");
    exit_button->Connect("Clicked()", "MyMainFrame", this, "exit_button_clicked()"); // Connect to exit handler
    grid_frame_4->AddFrame(exit_button, new TGLayoutHints(kLHintsCenterX, 5, 5, 5, 0));
    
    AddFrame(grid_frame_1, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    AddFrame(grid_frame_2, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    AddFrame(grid_frame_3, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    AddFrame(grid_frame_4, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
 
    text_output = new TGTextView(this, 600, 300); // 200x100 pixels size
    AddFrame(text_output, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 10, 10, 0, 10));

    // Set up the main frame
    SetWindowName("CERN-ROOT based yield calculator by V. Ranga (2025)");
    MapSubwindows();
    Resize(GetDefaultSize());  // Automatically fit all widgets
    MapWindow();
}


MyMainFrame::~MyMainFrame() {
    // Cleanup dynamically allocated objects
    RemoveFrame(cal_yield_button);    delete cal_yield_button;
    Cleanup();
}

void MyMainFrame::cal_yield_button_clicked()
{
    
   // proj_integrated_current_entry->Modified();

    label->SetText("...........Working..........");
    
    total_charge_incident_int = total_charge_incident_entry->GetNumber();
    //cout << "total_charge_incident_int: " << total_charge_incident_int << endl;
    
    proj_charge_state_int = proj_charge_state_entry->GetNumber();
    //cout << "proj_charge_state_int: " << proj_charge_state_int << endl; 
    
    total_no_of_proj_double = proj_charge_state_int * total_charge_incident_int * 1e-9/(1.6e-19);
    //cout << "total_no_of_proj_double: " << total_no_of_proj_double << endl;

    // Convert double to scientific notation string
    std::stringstream ss;
    ss << std::scientific << std::setprecision(2) << total_no_of_proj_double;
    total_no_of_proj_string = TGString(ss.str().c_str());
    
    //cout << "total_no_of_proj_string: " << total_no_of_proj_string << endl;
    total_no_of_proj_label->SetText(total_no_of_proj_string);
    label->SetText("Calculations Complete");
    return;
}



// Function to update TGTextView in real time
void MyMainFrame::update_text_output()
{
    text_output->Update();  // Force immediate UI refresh
    gSystem->ProcessEvents(); // Process pending UI events
    return;
}



void MyMainFrame::exit_button_clicked()
{
    text_output->AddLine("Exiting application..."); // Add exit message
    gApplication->Terminate(0); // Gracefully exit the application
}

// Properly handle window close
void MyMainFrame::CloseWindow() {
    std::cout << "Closing application...\n";
    gApplication->Terminate(0);  // Stops the ROOT event loop
}

int yield_cal() 
{
    TApplication app("ROOT Application", 0, nullptr);
    MyMainFrame *mainFrame = new MyMainFrame(gClient->GetRoot(), 700, 700);
    app.Run();

    delete mainFrame;
    return 0;
}
